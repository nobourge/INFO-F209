//
// Created by Anton Romanova on 26/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_MODELS_API_WRAPPER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_MODELS_API_WRAPPER_H_

#include "../../common/base64.h"
#include "../../common/constants.h"
#include "user_client.h"
#include "requests.h"
#include "../../common/models/user/message.h"
#include <string>

struct ApiError {
  std::string error_message;
};

typedef bool IsAdmin;

struct LoginError: ApiError {
};

class ApiWrapper {
public:
  ApiWrapper(const std::string &login, const std::string &password);
  static std::variant<UserClient, LoginError> GetCurrentUserFromSharedApiWrapperInstance();


  std::variant<UserClient, LoginError> GetCurrentUser();


  // general purpose
  static std::variant<std::vector<UserClient>, ApiError> GetAllUsers();
  static std::variant<std::vector<UserClient>, ApiError> GetAllUsersExceptCurrentUser();
  static std::vector<UserClient> GetUsersRanked(unsigned max_num_users);


  // account
  static std::variant<ApiWrapper, LoginError> Login(const std::string &login, const std::string &password);
  static std::variant<ApiWrapper, ApiError> CreateAccount(const std::string &login, const std::string &password);


  // friends
  std::optional<ApiError> AddFriend(const UserClient &user);
  std::variant<std::vector<Message>, ApiError> GetConversationWithUser(const UserClient &other_user);
  std::optional<ApiError> SendNewMessage(const UserClient &user, const string &message);


  // game
  std::variant<std::vector<object_id_t>, ApiError> GetGamesVector();


  static std::optional<ApiWrapper> &GetShared();

private:
  constexpr static const char api_url_[] =
      "http://" LOCALHOST ":" SERVER_PORT_S "/api/v1/";

  std::string login_;
  std::string password_;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_MODELS_API_WRAPPER_H_
