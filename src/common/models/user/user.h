//
// Created by Anton Romanova on 17/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_H_

#include "../../../common/constants.h"
#include "../../constants.h"
#include "../serializable.h"
#include "password.h"
#include "username.h"
#include <memory>
#include <unordered_set>
#include <utility>

class User : public std::enable_shared_from_this<User> {
public:
  User();
  User(const User &other) = default;
  User(User &&other) noexcept;
  User &operator=(const User &) = default;
  User(const Username &username, const std::optional<std::string> &password,
       uint32_t score, const std::unordered_set<uint32_t> &invitee_games = {},
       const std::unordered_set<uint32_t> &admin_games = {});

  [[nodiscard]] const Username &GetUsername() const;

  [[nodiscard]] int64_t GetCreationTimestamp() const;

  [[nodiscard]] uint32_t GetScore() const;

  object_id_t GetId() const;

  void NewFriend(User &new_friend);

  virtual std::unordered_set<object_id_t> GetFriendsIds() const;

  void SetFriendsIds(const std::unordered_set<uint32_t> &friends_ids);

  const std::optional<std::string> &GetPassword() const;

  const std::unordered_set<uint32_t> &GetInviteeGameIds() const;
  const std::unordered_set<uint32_t> &GetAdminGameIds() const;

  void SetInviteeGameIds(const std::unordered_set<uint32_t> &invitee_game_ids);
  void SetAdminGameIds(const std::unordered_set<uint32_t> &admin_game_ids);

protected:
  void SetId(object_id_t id);

protected:
  User(const object_id_t id, const Username &username,
       const std::optional<std::string> &password,
       const int64_t &creation_timestamp, const uint32_t &score,
       std::unordered_set<object_id_t> &&friends_ids_ = {});

private:
  object_id_t id_;
  Username username_;
  std::optional<std::string> password_;
  int64_t creation_timestamp_;
  uint32_t score_;
  std::unordered_set<object_id_t> friends_ids_ = {};
  std::unordered_set<object_id_t> invitee_game_ids_ = {};
  std::unordered_set<object_id_t> admin_game_ids_ = {};
};

#endif // QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_H_
