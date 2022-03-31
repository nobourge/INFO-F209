//
// Created by Anton Romanova on 31/03/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_UTILS_H_
#define QUORIDOR_SRC_SERVER_SIDE_UTILS_H_

#include "../client_side/models/api_wrapper.h"
#include "../common/base64.h"
#include "../common/models/user_server.h"

#define VALIDATE_CREDENTIALS(req)                                              \
  auto __optional_user = AuthenticateUser(req);                                \
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

template <typename... Args>
using ApiViewFunction =
    std::function<crow::json::wvalue(const crow::request &, Args...)>;

template <typename... Args>
using ApiAuthedViewFunction = std::function<crow::json::wvalue(
    UserServer &, const crow::request &, Args...)>;

/// prend en paramètre un message
/// et s’occupe de prevenir une SQL Injection en levant une erreur
/// si le now d'utilisateur ou le mot de passe contiennent les characters
/// ' " ; ? ,
static bool AreCharsValid(const std::string &msg) {
  return msg.find_first_of("\"',\\;:?") == std::string::npos;
}

/// Effectue l'extraction du username et mdp à partir d'une requête http
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

/// Authentifie l'utilisateur à partir d'une requête http
static std::optional<UserServer>
AuthenticateUser(const crow::request &request) {
  auto username_and_password = ExtractUsernameAndPassword(request);

  if (username_and_password.has_value()) {
    std::string username_str = std::get<0>(*username_and_password);
    std::string password_str = std::get<1>(*username_and_password);

    std::unique_ptr<Username> username;
    std::unique_ptr<Password> password;

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

/// Sérialise une liste de User
static crow::json::wvalue
SerializeUsersVector(std::unique_ptr<std::vector<UserServer>> users) {
  crow::json::wvalue users_json;
  for (int i = 0; i < users->size(); i++) {
    users_json[i] = std::move(users->at(i).Serialize());
  }
  return users_json;
}

/// Prend en paramètre une fonction qui prend en paramètre un utilisateur
/// authentifié et renvoie une fonction qui prend en paramètre seulement une
/// requête et effectue automatiquement l'authentification.
///
/// @code
/// crow::json::wvalue SomeView(UserServer &u, const crow::request &r) {...}
/// crow::json::wvalue res = Auth(SomeView) (my_request)
/// @endcode
///
template <typename... Args, typename Func>
static ApiViewFunction<Args...> Auth(const Func &original_function) {
  return [&](const crow::request &req, Args... args) {
    VALIDATE_CREDENTIALS(req);
    return original_function(user, req, args...);
  };
}

#endif // QUORIDOR_SRC_SERVER_SIDE_UTILS_H_
