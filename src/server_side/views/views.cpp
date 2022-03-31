//
// Created by Anton Romanova on 31/03/2022.
//

#include "views.h"

crow::json::wvalue RankingListView(const crow::request &request) {
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
}

crow::json::wvalue UserExceptMeListView(UserServer &user,
                                        const crow::request &) {
  auto users = UserServer::GetAllObjectsFromDB();

  users->erase(std::remove_if(users->begin(), users->end(),
                              [&](UserServer const &u) {
                                return u.GetId() == user.GetId();
                              }),
               users->end());

  crow::json::wvalue output;
  output["users"] = SerializeUsersVector(std::move(users));
  return output;
}

crow::json::wvalue ThisUserDetailView(UserServer &user, const crow::request &) {
  return user.Serialize();
}

crow::json::wvalue AddFriendView(UserServer &user,
                                 const crow::request &request) {
  auto username_unparsed = request.url_params.get("username");

  API_GUARD(username_unparsed, "No username provided");
  API_GUARD(AreCharsValid(username_unparsed), "Invalid characters in username");

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
}

crow::json::wvalue MyGamesListView(UserServer &user, const crow::request &) {
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
}

crow::json::wvalue GameDetailView(UserServer &user, const crow::request &,
                                  uint32_t game_id) {
  auto game = DataBase::GetInstance()->GetGame(game_id);
  API_GUARD(game.has_value(), "Inexistant game");

  crow::json::wvalue output;
  output["success"] = true;
  output["game"] = game->GetGameJson();

  return output;
}

crow::json::wvalue GameRepresentationView(UserServer &user,
                                          const crow::request &,
                                          uint32_t game_id) {
  auto game = DataBase::GetInstance()->GetGame(game_id);
  API_GUARD(game.has_value(), "Inexistant game");

  crow::json::wvalue output;
  output["success"] = true;
  output["game_repr"] = game->GetBoard()->GetBoardString();

  return output;
}

crow::json::wvalue GameIsMyTurnView(UserServer &user, const crow::request &,
                                    uint32_t game_id) {
  auto game = DataBase::GetInstance()->GetGame(game_id);
  API_GUARD(game.has_value(), "Inexistant game");

  crow::json::wvalue output;

  output["success"] = true;

  output["my_turn"] =
      game->GetCurrentPlayer() != nullptr
          ? game->GetCurrentPlayer()->GetUserId() == user.GetId()
          : false;

  return output;
}

crow::json::wvalue SubmitGameMoveView(UserServer &user,
                                      const crow::request &request,
                                      uint32_t game_id) {
  auto game = DataBase::GetInstance()->GetGame(game_id);
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

  DataBase::GetInstance()->SaveGame(game_id, *game);

  output["success"] = true;

  return output;
}

crow::json::wvalue SubmitNewGameView(UserServer &user,
                                     const crow::request &request) {
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
}

crow::json::wvalue CreateNewUserView(const crow::request &request) {
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
  output["user"] = std::move(user->Serialize());
  output["success"] = true;
  return output;
}

crow::json::wvalue SendMessageView(UserServer &user,
                                   const crow::request &request) {
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
}

crow::json::wvalue MessagesListView(UserServer &user,
                                    const crow::request &request) {
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
    output["messages"][i] = std::move(messages.at(i).Serialize());

  output["success"] = true;

  return output;
}
