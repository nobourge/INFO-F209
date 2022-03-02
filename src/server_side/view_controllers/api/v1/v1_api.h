//
// Created by Anton Romanova on 15/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_
#define QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_

#include "../base_quoridor_api.h"
#include "../../../models/user_server.h"
#include "../../../../common/base64.h"
#include "../../../../client_side/models/api_wrapper.h"
#include <memory>

#define V1_API_PREFIX "/api/v1/"  // PREFIX :
#define API_ROUTE(app, url) app.template route<crow::black_magic::get_parameter_tag(url)>(url)
#define VALIDATE_CREDENTIALS(req, output)       auto optional_user = AuthenticateUser(request); \
                                                if (!optional_user.has_value()) { \
                                                  output["error"] = "Invalid credentials"; \
                                                  return output; \
                                                }

///

static std::optional<std::tuple<std::string, std::string>> ExtractUsernameAndPassword(const crow::request &request) {
  std::string auth = request.get_header_value(AUTHORIZATION_HEADER_NAME);
  if (auth.size() < ENCODED_CREDENTIALS_START_AT_POS + 1) {
    return {};
  }
  std::string credentials_encoded = auth.substr(ENCODED_CREDENTIALS_START_AT_POS);
  std::string credentials = base64_decode(credentials_encoded);
  size_t found = credentials.find(AUTHORIZATION_HEADER_CRED_SEPARATOR);
  if (found != std::string::npos) {
    if (credentials.find(AUTHORIZATION_HEADER_CRED_SEPARATOR, found + 1) != std::string::npos) {
      // there are more than one separator, we cannot know where the actual separator is
      return {};
    }
    std::string username = credentials.substr(0, found);
    std::string password = credentials.substr(found + 1);

    return {{ username, password }};
  }
  return {};
}

/// prend en paramètre un message
/// et s’occupe de Prevenir une SQL Injection en levant une erreur
/// si le now d'utilisateur ou le mot de passe contiennent les caracteres:
/// '
/// "
/// ;
/// ?
/// ,
/// \param lettres
/// \return
static crow::json::wvalue PreventSQLInjection(const std::string& msg)
{
  crow::json::wvalue output;

  for (auto & c : msg) {
    int a = c;
    if ((34 == a )
    || (39 == a )
    || (44 == a )
    || (59 == a )
    || (63 == a ))
    {
      output["error"] = "Invalid caracters";
      return output;
    }
  }
}


static std::optional<UserServer> AuthenticateUser(const crow::request &request) {
    auto username_and_password = ExtractUsernameAndPassword(request);

    if (username_and_password.has_value()) {
      std::string username_str = std::get<0>(*username_and_password);
      std::string password_str = std::get<1>(*username_and_password);

      std::unique_ptr<Username> username = nullptr;
      std::unique_ptr<Password> password = nullptr;

      try {
        username = std::make_unique<Username>(username_str);
        password = std::make_unique<Password>(password_str);
      } catch (const std::exception &) {
        return {};
      }

      auto user = UserServer::InitFromDB(*username);

      if (user.has_value() && user->GetPassword().has_value() && *user->GetPassword() == (*password).GetValue()) {
        return user;
      }
    }

  return {};
}


static crow::json::wvalue SerializeUsersVector(std::unique_ptr<std::vector<UserServer>> users) {
  crow::json::wvalue users_json;
  for (int i = 0; i < users->size(); i++) {
    //        std::cout << std::move(*(users->at(i).Serialize())) << std::endl;
    users_json[i] = std::move(*(users->at(i).Serialize()));
  }
  return users_json;
}

template<class ...Middlewares>
class V1Api : public BaseQuoridorApi {
 public:

  V1Api() {

    SetupRoutes();
  };

  [[nodiscard]] unsigned int GetVersion() const;
 protected:

  void SetupRoutes() override {
    BaseQuoridorApi::SetupRoutes();

    API_ROUTE(GetApp(), "/api/v1/users")([]() {
      crow::json::wvalue output;
      output["users"] = SerializeUsersVector(UserServer::GetAllObjectsFromDB());
      return output;
    });

    API_ROUTE(GetApp(), "/api/v1/users/ranking")([](const crow::request &request) {
      std::optional<unsigned int> num_users = {};
      crow::json::wvalue output;
      auto num_users_unparsed = request.url_params.get("max_num_users");
      if (num_users_unparsed == nullptr) {
        num_users = MAX_NUM_USERS_RANKING_DEFAULT;
      }

      if (num_users_unparsed) {
        try {
          num_users = std::stoul(num_users_unparsed);
        } catch (...) {
          output["error"] = "Invalid number of users";
        }
      }

      if (num_users.has_value()) {
        if (*num_users > MAX_NUM_USERS_RANKING_PER_REQUEST) {
          output["error"] = "Too many users requested";
        } else {
          output["users"] = SerializeUsersVector(UserServer::GetRankingFromDB(*num_users));
        }
      }

      return output;
    });

    ///

    API_ROUTE(GetApp(), "/api/v1/user/<string>")([](const std::string &username) {
      UserServer user{Username{username}, 0};
      return *user.Serialize();
    });

    API_ROUTE(GetApp(), "/api/v1/me")([](const crow::request &request) {
      crow::json::wvalue output;
      VALIDATE_CREDENTIALS(requests, output);

      return *(optional_user->Serialize());
    });

    API_ROUTE(GetApp(), "/api/v1/me/add_friend") ([] (const crow::request &request) {
      crow::json::wvalue output;
      output["success"] = false;
      VALIDATE_CREDENTIALS(request, output);


      auto username_unparsed = request.url_params.get("username");

      if (username_unparsed == nullptr) {
        output["error"] = "No username provided";
        return output;
      }

      std::unique_ptr<Username> username = nullptr;

      try {
        username = std::make_unique<Username>(username_unparsed);
      } catch (const InvalidUsernameError &error) {
        output["error"] = "Invalid username";
        return output;
      }

      auto other_user = UserServer::InitFromDB(*username);

      if (!other_user.has_value()) {
        output["error"] = "No user with this username";
        return output;
      }

      if (other_user->GetId() == optional_user->GetId()) {
        output["error"] = "Cannot add yourself as friend";
        return output;
      }

      const auto &friends_ids = optional_user->GetFriendsIds();
      if (friends_ids.find(other_user->GetId()) != friends_ids.end()) {
        output["error"] = "Friend already added";
        return output;
      }

      optional_user->AddFriendAndSaveToDb(*other_user);
      output["success"] = true;
      return output;
    });

    API_ROUTE(GetApp(), "/api/v1/me/games")([](const crow::request &request) {
      crow::json::wvalue output;
      VALIDATE_CREDENTIALS(requests, output);

      User &user = *optional_user;

      return *(optional_user->Serialize());
    });

    API_ROUTE(GetApp(), "/api/v1/me/games/<uint>")([](const crow::request &request, unsigned int game_id) {
      crow::json::wvalue output;
      VALIDATE_CREDENTIALS(requests, output);

      User &user = *optional_user;

      return *(optional_user->Serialize());
    });

    API_ROUTE(GetApp(), "/api/v1/new_user") ([](const crow::request &request) {
      crow::json::wvalue output;
      output["success"] = false;

      auto username_and_password = ExtractUsernameAndPassword(request);
      if (username_and_password.has_value()) {
        std::string username_str = std::get<0>(*username_and_password);
        std::string password_str = std::get<1>(*username_and_password);

        // todo: check input for sql injection
        PreventSQLInjection(username_str);
        PreventSQLInjection(password_str);

        std::unique_ptr<Username> username = nullptr;
        std::unique_ptr<Password> password = nullptr;

        try {
          username = std::make_unique<Username>(username_str);
          password = std::make_unique<Password>(password_str);
        } catch (const std::exception &err) {
          output["error"] = err.what();
          return output;
        }

        auto user = UserServer::NewUser(*username, password->GetValue());

        if (!user.has_value()) {
          output["error"] = "Failed to create user";
          return output;
        } else {
          output["user"] = std::move(*user->Serialize());
          output["success"] = true;
        }


      } else {
        output["error"] = "Failed to create user. No authentication data provided";
      }
      return output;
    });




//    API_ROUTE(GetApp(), "api/v1/users/<string>/") ([] (const crow::request))

  }
 private:
  static constexpr const unsigned version_ = 0;
};

#undef V1_API_PREFIX

#endif //QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_
