//
// Created by Anton Romanova on 28/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_MODELS_USER_CLIENT_H_
#define QUORIDOR_SRC_CLIENT_SIDE_MODELS_USER_CLIENT_H_

#include "../../common/models/user/user.h"

class UserClient : public User {
public:

  UserClient() = default;
  UserClient(const UserClient &) = default;
  UserClient &operator=(const UserClient &) = default;
  UserClient(UserClient &&) = default;
  UserClient(const Username &username);
  explicit UserClient(const crow::json::rvalue &json);
  const std::vector<UserClient> &GetFriends() const;

  std::unordered_set<uint32_t> GetFriendsIds() const override;

private:
  std::vector<UserClient> friends_;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_MODELS_USER_CLIENT_H_

