//
// Created by Anton Romanova on 26/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_MODELS_API_WRAPPER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_MODELS_API_WRAPPER_H_

#include <string>
#include "../../common/models/user/user.h"
#include "../../common/constants.h"

class ApiWrapper {
public:
  ApiWrapper();

  static std::unique_ptr<std::vector<User>> GetUsersRanked(unsigned max_num_users);
  static std::string ReceiveNewMessages(int id);

private:
  constexpr static const char url_[] = "http://" LOCALHOST ":" SERVER_PORT_S "/api/v1/";
};


#endif // QUORIDOR_SRC_CLIENT_SIDE_MODELS_API_WRAPPER_H_
