//
// Created by Anton Romanova on 17/02/2022.
//

#include "user.h"
#include "../../../server_side/models/database.h"
#include "../../utils.h"

const Username &User::GetUsername() const { return username_; }

User::User(const Username &username, const std::optional<std::string> &password,
           uint32_t score)
    : username_(username), password_(password),
      creation_timestamp_(GET_UNIX_TIMESTAMP), score_(score) {}

int64_t User::GetCreationTimestamp() const { return creation_timestamp_; }

uint32_t User::GetScore() const { return score_; }

object_id_t User::GetId() const { return id_; }

///
/// \param new_friend
void User::NewFriend(User &new_friend) {
  friends_ids_.insert(new_friend.id_);
  new_friend.friends_ids_.insert(id_);
}

///
User::User()
    : id_(0),
    username_(),
    password_(),
    creation_timestamp_(GET_UNIX_TIMESTAMP),
    score_(0) {}

///
/// \return
std::unordered_set<uint32_t> User::GetFriendsIds() const {
  return friends_ids_;
}

///
/// \param friends_ids
void User::SetFriendsIds(const unordered_set<uint32_t> &friends_ids) {
  friends_ids_ = friends_ids;
}

///
/// \param id
/// \param username
/// \param password
/// \param creation_timestamp
/// \param score
/// \param friends_ids
User::User(const object_id_t id,
           const Username &username,
           const std::optional<std::string> &password,
           const int64_t &creation_timestamp,
           const uint32_t &score,
           std::unordered_set<object_id_t> &&friends_ids)
    : id_(id),
    username_(username),
    password_(password),
    creation_timestamp_(creation_timestamp),
    score_(score),
    friends_ids_(friends_ids) {}

///
const optional<std::string> &User::GetPassword() const { return password_; }

///
/// \param id
void User::SetId(object_id_t id) { id_ = id; }

///
/// \param other
User::User(User &&other) noexcept
    : id_(other.id_),
    username_(std::move(other.username_)),
    password_(std::move(other.password_)),
    creation_timestamp_((other.creation_timestamp_)),
    score_(other.score_),
    friends_ids_(std::move(other.friends_ids_)) {}
