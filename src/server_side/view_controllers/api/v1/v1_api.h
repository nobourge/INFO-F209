//
// Created by Anton Romanova on 15/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_
#define QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_

#include "../../../../client_side/models/api_wrapper.h"
#include "../../../../common/base64.h"
#include "../../../../common/models/user_server.h"
#include "../base_quoridor_api.h"
#include <memory>

#define V1_API_PREFIX "/api/v1/" // PREFIX :
#define API_ROUTE(app, url)                                                    \
  app.template route<crow::black_magic::get_parameter_tag(url)>(url)
#define VALIDATE_CREDENTIALS(req)                                              \
  auto __optional_user = AuthenticateUser(request);                            \
  if (!__optional_user.has_value()) {                                          \
    crow::json::wvalue __output;                                               \
    (__output)["success"] = false;                                             \
    (__output)["error"] = "Invalid credentials";                               \
    return (__output);                                                         \
  }                                                                            \
  UserServer user = *__optional_user;

#define RETURN_SUCCESS_JSON                                                    \
  crow::json::wvalue __success_output;                                         \
  __success_output["success"] = true;                                          \
  return __success_output;

#define API_GUARD(condition, error_message)                                    \
  if (!(condition)) {                                                          \
    crow::json::wvalue __output;                                               \
    __output["success"] = false;                                               \
    __output["error"] = error_message;                                         \
    return (__output);                                                         \
  }
/// prend en paramètre un message
/// et s’occupe de prevenir une SQL Injection en levant une erreur
/// si le now d'utilisateur ou le mot de passe contiennent les caracteres:
/// '
/// "
/// ;
/// ?
/// ,
/// \param lettres
/// \return
static bool AreCharsValid(const std::string &msg) {
  // these chars can be used for a sql injection attack;
  return msg.find_first_of("\"',\\;:?") == std::string::npos;
}

static std::optional<std::tuple<std::string, std::string>>
ExtractUsernameAndPassword(const crow::request &request) {
  std::string auth = request.get_header_value(AUTHORIZATION_HEADER_NAME);
  if (auth.size() < ENCODED_CREDENTIALS_START_AT_POS + 1) {
    return {};
  }
  std::string credentials_encoded =
      auth.substr(ENCODED_CREDENTIALS_START_AT_POS);
  std::string credentials = base64_decode(credentials_encoded);
  size_t found = credentials.find(AUTHORIZATION_HEADER_CRED_SEPARATOR);
  if (found != std::string::npos) {
    if (credentials.find(AUTHORIZATION_HEADER_CRED_SEPARATOR, found + 1) !=
        std::string::npos) {
      // there are more than one separator, we cannot know where the actual
      // separator is
      return {};
    }
    std::string username = credentials.substr(0, found);
    std::string password = credentials.substr(found + 1);

    if (!AreCharsValid(username + password)) {
      return {};
    }

    return {{username, password}};
  }
  return {};
}

static std::optional<UserServer>
AuthenticateUser(const crow::request &request) {
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

    if (user.has_value() && user->GetPassword().has_value() &&
        *user->GetPassword() == (*password).GetValue()) {
      return user;
    }
  }

  return {};
}

static crow::json::wvalue
SerializeUsersVector(std::unique_ptr<std::vector<UserServer>> users) {
  crow::json::wvalue users_json;
  for (int i = 0; i < users->size(); i++) {
    users_json[i] = std::move(*(users->at(i).Serialize()));
  }
  return users_json;
}

template <class... Middlewares> class V1Api : public BaseQuoridorApi {
public:
  V1Api() { SetupRoutes(); };

  [[nodiscard]] unsigned int GetVersion() const;

protected:
  void SetupRoutes() override {
    BaseQuoridorApi::SetupRoutes();

    // this is a temporary solution... we hadn't the time to save game to db

    API_ROUTE(GetApp(), "/api/v1/users")
    ([]() {
      crow::json::wvalue output;
      output["users"] = SerializeUsersVector(UserServer::GetAllObjectsFromDB());
      return output;
    });

    API_ROUTE(GetApp(), "/api/v1/me/all-users-except-me")
        ([](const crow::request &request) {
          VALIDATE_CREDENTIALS(requests);

          auto users = UserServer::GetAllObjectsFromDB();

          users->erase(std::remove_if(users->begin(), users->end(), [&](UserServer const& u) {
            return u.GetId() == user.GetId();
          }), users->end());

          crow::json::wvalue output;
          output["users"] =
              SerializeUsersVector(std::move(users));
          return output;
        });


    API_ROUTE(GetApp(), "/api/v1/users/ranking")
    ([](const crow::request &request) {
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
          output["users"] =
              SerializeUsersVector(UserServer::GetRankingFromDB(*num_users));
        }
      }

      return output;
    });

    API_ROUTE(GetApp(), "/api/v1/me")
    ([](const crow::request &request) {
      VALIDATE_CREDENTIALS(requests);

      return *(user.Serialize());
    });

    API_ROUTE(GetApp(), "/api/v1/me/add_friend")
    ([](const crow::request &request) {
      VALIDATE_CREDENTIALS(request);

      auto username_unparsed = request.url_params.get("username");

      API_GUARD(username_unparsed, "No username provided");
      API_GUARD(AreCharsValid(username_unparsed),
                "Invalid characters in username");

      std::unique_ptr<Username> username;

      try {
        username = std::make_unique<Username>(username_unparsed);
      } catch (const InvalidUsernameError &error) {
        API_GUARD(false, "Invalid username");
      }

      auto other_user = UserServer::InitFromDB(*username);

      API_GUARD(other_user.has_value(), "No user with this username");
      API_GUARD(other_user->GetId() != user.GetId(),
                "Cannot add yourself as friend");

      const auto &friends_ids = user.GetFriendsIds();

      API_GUARD(friends_ids.find(other_user->GetId()) == friends_ids.end(),
                "Friend already added");

      user.AddFriendAndSaveToDb(*other_user);
      RETURN_SUCCESS_JSON
    });

    API_ROUTE(GetApp(), "/api/v1/me/games")
    ([](const crow::request &request) {
      VALIDATE_CREDENTIALS(requests);
      crow::json::wvalue output;
      output["success"] = true;

      auto games = DataBase::GetInstance()->GetAllGamesForUser(user.GetId());

      if (games.empty()) {
        output["games"] = std::vector<std::string>();
      } else {
        for (int i = 0; i < games.size(); i++) {
          output["games"][i]["id"] = std::get<0>(games[i]);
          output["games"][i]["name"] = std::get<1>(games[i]);
        }
      }

      return output;
    });

    API_ROUTE(GetApp(), "/api/v1/me/game/<uint>")
    ([](const crow::request &request, object_id_t game_index) {
      VALIDATE_CREDENTIALS(request);

      auto game = DataBase::GetInstance()->GetGame(game_index);
      API_GUARD(game.has_value(), "Inexistant game");

      crow::json::wvalue output;
      output["success"] = true;
      output["game"] = game->GetGameJson();

      return output;
    });

    API_ROUTE(GetApp(), "/api/v1/me/game/<uint>/repr")
    ([](const crow::request &request, object_id_t game_index) {
      VALIDATE_CREDENTIALS(request);

      auto game = DataBase::GetInstance()->GetGame(game_index);
      API_GUARD(game.has_value(), "Inexistant game");

      crow::json::wvalue output;
      output["success"] = true;
      output["game_repr"] = game->GetBoard()->GetBoardString();

      return output;
    });

    API_ROUTE(GetApp(), "/api/v1/me/game/<uint>/my_turn")
    ([](const crow::request &request, object_id_t game_index) {
      VALIDATE_CREDENTIALS(request);

      auto game = DataBase::GetInstance()->GetGame(game_index);
      API_GUARD(game.has_value(), "Inexistant game");

      crow::json::wvalue output;

      output["success"] = true;

      output["my_turn"] =
          game->GetCurrentPlayer() != nullptr
              ? game->GetCurrentPlayer()->GetUserId() == user.GetId()
              : false;

      return output;
    });

    API_ROUTE(GetApp(), "/api/v1/me/game/<uint>/move")
    ([](const crow::request &request, object_id_t game_index) {
      VALIDATE_CREDENTIALS(request);

      auto game = DataBase::GetInstance()->GetGame(game_index);
      API_GUARD(game.has_value(), "Inexistant game");

      auto action_unparsed = request.url_params.get("move_value");

      API_GUARD(action_unparsed != nullptr,
                "No object specified to perform the move");

      std::string move = action_unparsed;

      API_GUARD(game->GetCurrentPlayer() != nullptr, "No current user");
      API_GUARD(game->GetCurrentPlayer()->GetUserId() == user.GetId(),
                "It is not your turn");
      API_GUARD(game->GameOnGoing(), "Game has finished");

      crow::json::wvalue output;
      auto move_ret = game->PlayMove(move);
      API_GUARD(!move_ret.has_value(), *move_ret)

      DataBase::GetInstance()->SaveGame(game_index, *game);

      output["success"] = true;

      return output;
    });

    API_ROUTE(GetApp(), "/api/v1/me/games/new")
    ([](const crow::request &request) {
      VALIDATE_CREDENTIALS(requests);

      std::vector<UserServer> participants = {user};

      auto participants_unparsed =
          request.url_params.get_list("participants", false);

      API_GUARD(participants_unparsed.size() == 1,
                "Only 2 participants are supported for now")

      for (std::string participant_str : participants_unparsed) {
        API_GUARD(AreCharsValid(participant_str),
                  "Illegal chars in participant_str username");
        try {
          auto participant =
              UserServer::InitFromDB(Username{std::move(participant_str)});
          API_GUARD(participant.has_value(), "Inexistant participant");
          participants.push_back(*participant);
        } catch (const std::exception &err) {
          API_GUARD(false, err.what());
        }
      }

      API_GUARD(participants.size() == 2, "Invalid number of participants");

      API_GUARD(participants[0].GetId() != participants[1].GetId(),
                "Cannot add yourself as second player");

      auto room_name = request.url_params.get("room_name");

      API_GUARD(room_name != nullptr, "No room name specified");

      std::shared_ptr<Game> game;

      try {
        game = std::make_shared<Game>(room_name, 2);
      } catch (const std::exception &err) {
        API_GUARD(false, err.what());
      }

      for (int i = 0; i < participants.size(); i++) {
        game->GetPlayers().at(i)->SetUser(participants[i].GetId());
      }

      game->SetAdminPlayer(game->GetPlayers().at(0));

      DataBase::GetInstance()->CreateGame(user.GetId(), room_name, *game);

      RETURN_SUCCESS_JSON;
    });


    API_ROUTE(GetApp(), "/api/v1/new_user")
    ([](const crow::request &request) {
      auto username_and_password = ExtractUsernameAndPassword(request);

      API_GUARD(username_and_password.has_value(),
                "Failed to create user. No authentication data provided");

      std::string username_str = std::get<0>(*username_and_password);
      std::string password_str = std::get<1>(*username_and_password);

      AreCharsValid(username_str);
      AreCharsValid(password_str);

      std::unique_ptr<Username> username = nullptr;
      std::unique_ptr<Password> password = nullptr;

      try {
        username = std::make_unique<Username>(username_str);
        password = std::make_unique<Password>(password_str);
      } catch (const std::exception &err) {
        API_GUARD(false, err.what(););
      }

      auto user = UserServer::NewUser(*username, password->GetValue());

      API_GUARD(user.has_value(), "Failed to create user");

      crow::json::wvalue output;
      output["user"] = std::move(*user->Serialize());
      output["success"] = true;
      return output;
    });

    API_ROUTE(GetApp(), "/api/v1/me/messages/send")
    ([](const crow::request &request) {
      VALIDATE_CREDENTIALS(request);
      auto receiver_username_unparsed = request.url_params.get("user");
      auto message_content_unparsed = request.url_params.get("content");

      API_GUARD(receiver_username_unparsed != nullptr,
                "no message receiver specified");
      API_GUARD(message_content_unparsed != nullptr, "no content specified");
      API_GUARD(AreCharsValid(receiver_username_unparsed),
                "Invalid characters in username");
      API_GUARD(AreCharsValid(message_content_unparsed),
                "Invalid characters in message");

      std::unique_ptr<UserServer> receiver_user;
      try {
        auto optional_user =
            UserServer::InitFromDB(Username(receiver_username_unparsed));

        API_GUARD(optional_user.has_value(), "Inexistant receiver");

        receiver_user = std::make_unique<UserServer>(*optional_user);
      } catch (const std::exception &err) {
        API_GUARD(false, err.what());
      }

      API_GUARD(receiver_user->GetId() != user.GetId(),
                "Cannot send a message to oneself");

      API_GUARD(
          user.SendMessageAndSaveToDb(*receiver_user, message_content_unparsed),
          "Undocumented error occurred");

      RETURN_SUCCESS_JSON
    });

    API_ROUTE(GetApp(), "/api/v1/me/messages")
    ([](const crow::request &request) {
      VALIDATE_CREDENTIALS(request)

      auto other_user_username_str = request.url_params.get("user");

      API_GUARD(other_user_username_str != nullptr,
                "Other user has not been given");

      std::unique_ptr<UserServer> other_user;

      try {
        auto optional_user =
            UserServer::InitFromDB(Username(other_user_username_str));
        API_GUARD(optional_user.has_value(), "No user with this username");
        other_user = std::make_unique<UserServer>(*optional_user);
      } catch (const std::exception &err) {
        API_GUARD(false, err.what());
      }

      auto messages = user.RetrieveMessagesWithUserFromDb(*other_user);

      crow::json::wvalue output;

      for (int i = 0; i < messages.size(); i++)
        output["messages"][i] = std::move(*messages.at(i).Serialize());

      output["success"] = true;

      return output;
    });
  }

private:
  static constexpr const unsigned version_ = 0;
};

#undef V1_API_PREFIX

#endif // QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_
