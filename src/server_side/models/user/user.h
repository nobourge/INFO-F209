//
// Created by Anton Romanova on 17/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_H_

#include "username.h"
#include "../serializable.h"
#include "../database_compatible.h"
#include "../../../common/constants.h"
#include <memory>

class User : public Serializable, public DatabaseCompatible<User>, public std::enable_shared_from_this<User> {
 public:
  User(const Username &username, uint32_t score);

  std::unique_ptr<crow::json::wvalue> Serialize() override;

  [[nodiscard]] const Username &GetUsername() const;

  [[nodiscard]] int64_t GetCreationTimestamp() const;

  [[nodiscard]] uint32_t GetScore() const;

  object_id_t GetId() const;

  void NewFriend(const User &new_friend);

  void SaveToDB() override;
  User &InitFromDB(object_id_t id) override;

 private:
  object_id_t id_;
  Username username_;
  int64_t creation_timestamp_;
  uint32_t score_;
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_H_
