//
// Created by Anton Romanova on 26/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_MODELS_API_WRAPPER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_MODELS_API_WRAPPER_H_

#include "../../common/base64.h"
#include "../../common/constants.h"
#include "user_client.h"
#include <string>

struct LoginError {
  std::string error_message;
};

class ApiWrapper {
public:
  ApiWrapper(const std::string &login, const std::string &password);


  //static std::unique_ptr<std::vector<User>> GetUsersRanked(unsigned max_num_users);
  static std::string ReceiveNewMessages(int id);

  static std::vector<UserClient> GetUsersRanked(unsigned max_num_users);

  std::variant<UserClient, LoginError> GetCurrentUser();

  static std::variant<ApiWrapper, LoginError> Login(const std::string &login, const std::string &password);


private:
  constexpr static const char url_[] =
      "http://" LOCALHOST ":" SERVER_PORT_S "/api/v1/";

  std::string login_;
  std::string password_;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_MODELS_API_WRAPPER_H_
