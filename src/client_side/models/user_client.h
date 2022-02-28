//
// Created by Anton Romanova on 28/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_MODELS_USER_CLIENT_H_
#define QUORIDOR_SRC_CLIENT_SIDE_MODELS_USER_CLIENT_H_

#include "../../common/models/user/user.h"
class UserClient : public User {
public:
    explicit UserClient(const crow::json::rvalue &json);

};

#endif // QUORIDOR_SRC_CLIENT_SIDE_MODELS_USER_CLIENT_H_
