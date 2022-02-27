//
// Created by Anton Romanova on 17/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_H_

#include "../../../common/constants.h"
#include "../../constants.h"
#include "../serializable.h"
#include "username.h"
#include <memory>

class User : public Serializable<User>,
             public std::enable_shared_from_this<User> {

public:
  User();
  explicit User(const crow::json::rvalue &json);
  User(const Username &username, uint32_t score);

  std::unique_ptr<crow::json::wvalue> Serialize() override;

  [[nodiscard]] const Username &GetUsername() const;

  [[nodiscard]] int64_t GetCreationTimestamp() const;

  [[nodiscard]] uint32_t GetScore() const;

  object_id_t GetId() const;

  void NewFriend(const User &new_friend);

  //  void SaveToDB() override;

  //  User &InitFromDB(object_id_t id);
  //  User &InitFromDB(const Username &username);
  std::optional<std::unique_ptr<User>> InitFromDB(const Username &username);
  bool SaveToDB();
  static std::unique_ptr<std::vector<User>> GetAllObjectsFromDB();
  static std::unique_ptr<std::vector<User>> GetRanking(int max_num_users);

private:
  static std::unique_ptr<std::vector<User>> UsersVectorFromUsersStringVector(
      const std::vector<std::vector<std::string>> &users_string_vector);

  User(const std::vector<std::string> &database_query_result);

  object_id_t id_;
  Username username_;
  int64_t creation_timestamp_;
  uint32_t score_;
};

#endif // QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_H_
