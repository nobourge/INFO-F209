//
// Created by Anton Romanova on 28/02/2022.
//

#include "user_client.h"

UserClient::UserClient(const crow::json::rvalue &json)
    : User(static_cast<int>(json["id"]), Username{json["username"].s()},
           {}, static_cast<int>(json["created_timestamp"]),
           static_cast<int>(json["score"])) {
  crow::json::rvalue friends_json_ = json["friends"];
  try {
    for (const auto &friend_json : friends_json_) {
      friends_.push_back(UserClient(friend_json));
    }
  } catch(const std::runtime_error &) {
    return;
  }
}

const std::vector<UserClient> &UserClient::GetFriends() const {
  return friends_;
}
std::unordered_set<uint32_t> UserClient::GetFriendsIds() const {
  auto friends = std::unordered_set<object_id_t>();

  for (const auto &user : GetFriends()) {
    friends.insert(user.GetId());
  }
  return friends;
}
UserClient::UserClient(const Username &username) : User(0, username, "", 0, 0, {}) {}
