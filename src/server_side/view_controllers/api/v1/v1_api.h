//
// Created by Anton Romanova on 15/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_
#define QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_

#include "../base_quoridor_api.h"
#include "../../../models/user/user.h"
#include "../../../../common/base64.h"

#define V1_API_PREFIX "/api/v1/"  // PREFIX :
#define API_ROUTE(app, url) app.template route<crow::black_magic::get_parameter_tag(url)>(url)
#define VALIDATE_CREDENTIALS(req, output)       auto optional_user = AuthenticateUser(request); \
                                                if (!optional_user.has_value()) { \
                                                  output["error"] = "Invalid credentials"; \
                                                  return output; \
                                                }

static std::unique_ptr<std::vector<User>> GenerateUsers(unsigned num_users) {
  auto users = std::make_unique<std::vector<User>>();

  for (int i = 0; i < num_users; i++) {
    std::string username = "User" + std::to_string(i);
    uint32_t score = i;
    users->push_back(User(Username(username), score));
  }

  return users;
}

static std::optional<User> AuthenticateUser(const crow::request &request) {
//  request.headers
  std::string auth = request.get_header_value(AUTHORIZATION_HEADER_NAME);
  if (auth.size() < ENCODED_CREDENTIALS_START_AT_POS + 1) {
    return {};
  }
  std::string credentials_encoded = auth.substr(ENCODED_CREDENTIALS_START_AT_POS);
  std::string credentials = base64_decode(credentials_encoded);
  size_t found = credentials.find(AUTHORIZATION_HEADER_CRED_SEPARATOR);
  if (found != std::string::npos) {
    if (credentials.find(AUTHORIZATION_HEADER_CRED_SEPARATOR, found + 1) != std::string::npos ) {
      // there are more than one separator, we cannot know where the actual separator is
      return {};
    }
    std::string username = credentials.substr(0, found);
    std::string password = credentials.substr(found+1);

    return User(Username(username), 0); // we will validate password when the db is ready
  }

  return {};
}

static crow::json::wvalue GetUsersSerialized(unsigned num_users = 3, bool sort_scores = false) {
  /// this is just a temporary function to generate random users_serialized
  crow::json::wvalue users_serialized;

  auto users = GenerateUsers(num_users);
  if (sort_scores) {
    std::sort(users->begin(), users->end(), [](const User &user1, const User &user2) {
      return user1.GetScore() > user2.GetScore();
    });
  }

  for (int i = 0; i < num_users; i++) {
    users_serialized[i] = std::move(*users->at(i).Serialize());
  }

  crow::json::wvalue output;
  output["users"] = std::move(users_serialized);
  return output;
}

template<class ...Middlewares>
class V1Api : public BaseQuoridorApi {
 public:

  V1Api() {
    ///

    SetupRoutes();
  };
///
/// \return
  [[nodiscard]] unsigned int GetVersion() const;
 protected:
  ///

  void SetupRoutes() override {
    BaseQuoridorApi::SetupRoutes();

    ///

    API_ROUTE(GetApp(), "/api/v1/users")([]() {
      return GetUsersSerialized();
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
          output = GetUsersSerialized(*num_users, true);
        }
      }

      return output;
    });

    ///

    API_ROUTE(GetApp(), "/api/v1/user/<string>")([](const std::string &username) {
      User user{Username{username}, 0};
      return *user.Serialize();
    });

    API_ROUTE(GetApp(), "/api/v1/me") ([] (const crow::request &request) {
      crow::json::wvalue output;
      VALIDATE_CREDENTIALS(requests, output);

      return *(optional_user->Serialize());
    });

    API_ROUTE(GetApp(), "/api/v1/me/games/<uint>") ([] (const crow::request &request, unsigned int game_id) {
      crow::json::wvalue output;
      VALIDATE_CREDENTIALS(requests, output);

      User &user = *optional_user;

      return *(optional_user->Serialize());
    });

//    API_ROUTE(GetApp(), "api/v1/users/<string>/") ([] (const crow::request))

  }
 private:
  static constexpr const unsigned version_ = 0;
};

#undef V1_API_PREFIX

#endif //QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_
