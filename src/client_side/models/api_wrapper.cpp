//
// Created by Anton Romanova on 26/02/2022.
//

#include "api_wrapper.h"
#include "requests.h"
#include <stdexcept>

#
std::vector<UserClient> ApiWrapper::GetUsersRanked(unsigned int max_num_users) {
  std::string url = api_url_;
  url += "users/ranking";
  auto json_res =
      Requests(url, {}, {{"max_num_users", std::to_string(max_num_users)}})
          .GetJson();
  crow::json::rvalue users_json;
  try {
    users_json = json_res["users"];
  } catch (const std::runtime_error &) {
    return {};
  }

  auto users = std::vector<UserClient>();
  users.reserve(users.size());
  for (auto &user_json : users_json) {
    users.push_back(UserClient(user_json));
  }
  return users;
}

ApiWrapper::ApiWrapper(const std::string &login, const std::string &password)
    : login_(login), password_(password) {}

std::variant<UserClient, LoginError> ApiWrapper::GetCurrentUser() {
  std::string url = api_url_;
  url += "me";

  std::variant<UserClient, LoginError> ret =
      LoginError{"A network error occurred"};
  crow::json::rvalue request_result_json;

  try {
    request_result_json = Requests(url, {{login_, password_}}).GetJson();
  } catch (const std::runtime_error &) {
    return ret;
  }

  try {
    ret = UserClient(request_result_json);
  } catch (const std::runtime_error &) {
    ret = LoginError{static_cast<std::string>(request_result_json["error"])};
  }
  return ret;
}

std::variant<ApiWrapper, LoginError>
ApiWrapper::Login(const std::string &login, const std::string &password) {
  auto api_wrapper = ApiWrapper(login, password);

  auto user = api_wrapper.GetCurrentUser();

  if (holds_alternative<LoginError>(user)) {
    return std::get<LoginError>(user);
  } else {
    GetShared() = api_wrapper;
    return api_wrapper;
  }
}

std::optional<ApiError> ApiWrapper::SendNewMessage(const UserClient &other_user,
                                                   const string &message) {
  auto user_or_err = ApiWrapper::GetCurrentUserFromSharedApiWrapperInstance();

  if (holds_alternative<LoginError>(user_or_err)) {
    return ApiError{std::get<LoginError>(user_or_err).error_message};
  }

  std::string url = api_url_;
  url += "me/messages/send";

  auto &this_user = std::get<UserClient>(user_or_err);

  crow::json::rvalue request_result_json;

  try {
    request_result_json =
        Requests(url, {{login_, password_}},
                 {{"user", other_user.GetUsername().GetValue()},
                  {"content", message}})
            .GetJson();
  } catch (...) {
    return ApiError{"A network error occurred"};
  }

  bool success = false;

  try {
    success = request_result_json["success"].b();
  } catch (const std::runtime_error &) {
    return ApiError{"Unknown error"};
  }

  if (!success) {
    std::string error_message = "Unknown error";
    try {
      error_message = static_cast<std::string>(request_result_json["error"]);
    } catch (const std::runtime_error &) {
    }
    return ApiError{error_message};
  }

  // successfully sent message!

  return {};
}

std::variant<ApiWrapper, ApiError>
ApiWrapper::CreateAccount(const std::string &login,
                          const std::string &password) {

  std::string url = api_url_;
  url += "new_user";

  std::variant<ApiWrapper, ApiError> ret =
      LoginError{"A network error occurred"};
  crow::json::rvalue request_result_json;

  try {
    request_result_json = Requests(url, {{login, password}}).GetJson();
  } catch (const std::runtime_error &) {
    return ret;
  }

  if (request_result_json["success"].b()) {
    GetShared() = ApiWrapper(login, password);
    ret = *GetShared();
  } else {
    ret = ApiError{static_cast<std::string>(request_result_json["error"])};
  }

  return ret;
}

std::variant<UserClient, LoginError>
ApiWrapper::GetCurrentUserFromSharedApiWrapperInstance() {
  if (ApiWrapper::GetShared().has_value()) {
    auto optional_user = ApiWrapper::GetShared()->GetCurrentUser();
    if (holds_alternative<UserClient>(optional_user)) {
      return std::get<UserClient>(optional_user);
    } else {
      return LoginError{"User is not signed in: " +
                        std::get<LoginError>(optional_user).error_message};
    }
  } else {
    return LoginError{"Sign in first"};
  }
}

std::optional<ApiWrapper> &ApiWrapper::GetShared() {
  static std::optional<ApiWrapper> shared_instance = {};
  return shared_instance;
}

std::variant<std::vector<UserClient>, ApiError> ApiWrapper::GetAllUsers() {
  std::string url = api_url_;
  url += "users";

  std::variant<std::vector<UserClient>, ApiError> ret =
      LoginError{"A network error occurred"};

  crow::json::rvalue request_result_json;

  try {
    request_result_json = Requests(url).GetJson();
  } catch (const std::runtime_error &) {
    return ret;
  }

  try {
    crow::json::rvalue users_json = request_result_json["users"];

    auto users = std::vector<UserClient>();
    users.reserve(users.size());
    for (auto &user_json : users_json) {
      users.emplace_back(user_json);
    }
    return users;
  } catch (const std::runtime_error &) {
    return ApiError{"Unknown error occurred"};
  }
}

std::variant<std::vector<UserClient>, ApiError> ApiWrapper::GetAllUsersExceptCurrentUser() {
  std::string url = api_url_;
  url += "me/all-users-except-me";

  std::variant<std::vector<UserClient>, ApiError> ret =
      LoginError{"A network error occurred"};

  crow::json::rvalue request_result_json;

  try {
    request_result_json = Requests(url).GetJson();
  } catch (const std::runtime_error &) {
    return ret;
  }

  try {
    crow::json::rvalue users_json = request_result_json["users"];

    auto users = std::vector<UserClient>();
    users.reserve(users.size());
    for (auto &user_json : users_json) {
      users.emplace_back(user_json);
    }
    return users;
  } catch (const std::runtime_error &) {
    return ApiError{"Unknown error occurred"};
  }
}

std::optional<ApiError> ApiWrapper::AddFriend(const UserClient &user) {
  auto user_requests_result = GetCurrentUser();
  if (holds_alternative<LoginError>(user_requests_result)) {
    return ApiError{std::get<LoginError>(user_requests_result).error_message};
  }

  auto this_user = std::get<UserClient>(user_requests_result);

  std::string url = api_url_;
  url += "me/add_friend";

  crow::json::rvalue response;
  try {
    response = Requests(url, {{login_, password_}},
                        {{"username", user.GetUsername().GetValue()}})
                   .GetJson();
  } catch (const std::runtime_error &error) {
    return ApiError{"Network error"};
  }

  bool success = false;
  std::string error_message = "Unknown error occurred";

  try {
    success = response["success"].b();
    if (!success) {
      error_message = response["error"].s();
    }
  } catch (const std::runtime_error &) {
  }

  if (success) {
    return {};
  } else {
    return ApiError{error_message};
  }
}

std::variant<std::vector<Message>, ApiError>
ApiWrapper::GetConversationWithUser(const UserClient &other_user) {

  std::string error_message = "An unknown error occurred";

  const auto kUserOrErr = GetCurrentUser();
  if (std::holds_alternative<LoginError>(kUserOrErr)) {
    return ApiError{std::get<LoginError>(kUserOrErr).error_message};
  }
  const auto kUser = std::get<UserClient>(kUserOrErr);

  std::string url = api_url_;
  url += "me/messages";

  std::variant<std::vector<Message>, ApiError> ret =
      LoginError{"A network error occurred"};

  crow::json::rvalue request_result_json;
  try {
    request_result_json =
        Requests(url, {{login_, password_}},
                 {{"user", other_user.GetUsername().GetValue()}})
            .GetJson();
  } catch (const std::runtime_error &err) {
    return ApiError{err.what()};
  } catch (...) {
    return ApiError{"A network error occurred"};
  }

  bool success = false;
  std::vector<Message> messages;

  try {
    success = request_result_json["success"].b();
    if (!success) {
      error_message = request_result_json["error"].s();
    }
  } catch (const std::runtime_error &err) {
    success = false;
  }

  if (success) {
    try {
      for (auto &message_json : request_result_json["messages"]) {
        auto message = Message::FromJson(message_json);
        if (message.has_value()) {
          messages.push_back(*message);
        }
      }
    } catch (const std::runtime_error &err) {
      // there are no messages, the server sent null
      messages = {};
    }
  }

  if (!success) {
    return ApiError{error_message};
  }

  return messages;
}

std::variant<std::vector<std::string>, ApiError> ApiWrapper::GetGamesVector() {
  std::string error_message = "An unknown error occurred";
  std::string url = api_url_;

  url += "me/games";

  crow::json::rvalue json_res;

  try {
    json_res = Requests(url, {{login_, password_}}).GetJson();
  } catch (const std::exception &err) {
    return ApiError{err.what()};
  }

  try {
    if (!json_res["success"].b()) {
      return ApiError{json_res["error"].s()};
    }
  } catch (const std::exception &err) {
    return ApiError{err.what()};
  }

  std::vector<std::string> games;

  for (const auto &game_id_json : json_res["games"]) {
    games.push_back(game_id_json["name"].s());
  }

  return games;
}

std::variant<std::string, ApiError> ApiWrapper::GetGameReprWithGameId(uint32_t game_id) {
  std::string url = api_url_;

  url += "me/game/" + std::to_string(game_id) + "/repr";

  crow::json::rvalue json_res;

  try {
    json_res = Requests(url, {{login_, password_}}).GetJson();
  } catch (const std::exception &err) {
    return ApiError{err.what()};
  }

  try {
    if (!json_res["success"].b()) {
      return ApiError{json_res["error"].s()};
    }
  } catch (const std::exception &err) {
    return ApiError{err.what()};
  }

  return json_res["game_repr"].s();
}

std::optional<ApiError> ApiWrapper::CreateGame(const std::string &room_name,
                                          const std::string &friend_username) {
  std::string url = api_url_;
  url += "me/games/new";
  crow::json::rvalue json_res;

  try {
    json_res = Requests(url, {{login_, password_}}, {{"participants", friend_username}, {"room_name", room_name}}).GetJson();
  } catch (const std::exception &err) {
    return ApiError{err.what()};
  }


  try {
    if (!json_res["success"].b()) {
      return {{json_res["error"].s()}};
    }
  } catch(...) {
    return {{"Unknown error occurred"}};
  }

  return {};
}

optional<ApiError> ApiWrapper::PerformGameMove(const object_id_t &game_id, const std::string &move) {
  std::string url = api_url_;
  url += "me/game/" + std::to_string(game_id) + "/move";

  crow::json::rvalue json_res;

  try {
    json_res = Requests(url, {{login_, password_}}, {{"move_value", move}}).GetJson();
  } catch (const std::exception &err) {
    return ApiError{err.what()};
  }
  try {
    if (!json_res["success"].b()) {
      return {{json_res["error"].s()}};
    }
  } catch(...) {
    return {{"Unknown error occurred"}};
  }

  return {};
}

std::variant<Game, ApiError> ApiWrapper::GetGame(uint32_t game_id) {
  std::string url = api_url_;

  url += "me/game/" + std::to_string(game_id);

  crow::json::rvalue json_res;

  try {
    json_res = Requests(url, {{login_, password_}}).GetJson();
  } catch (const std::exception &err) {
    return ApiError{err.what()};
  }

  try {
    if (!json_res["success"].b()) {
      return ApiError{json_res["error"].s()};
    }
  } catch (const std::exception &err) {
    return ApiError{err.what()};
  }

  auto game = Game::InitGameFromJson(json_res["game"]);

  if (!game.has_value()) {
    return ApiError{"Unknown error occurred. Failed to parse game"};
  }

  return *game;
}
