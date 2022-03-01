//
// Created by Anton Romanova on 28/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_SERVER_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_SERVER_H_

#include "../../common/models/user/user.h"

class UserServer : public User, public Serializable<User> {
public:
  bool SaveToDB();
  static std::optional<UserServer>
  InitFromDbByIdWithoutFriendList(const object_id_t id);
  static std::optional<UserServer> InitFromDB(const Username &username, const std::optional<std::string> &password = {});
  static std::optional<UserServer> NewUser(const Username &username, const std::string &password);

  static std::unique_ptr<std::vector<UserServer>> GetAllObjectsFromDB();
  static std::unique_ptr<std::vector<UserServer>> GetRankingFromDB(int max_num_users);

  std::unique_ptr<crow::json::wvalue> Serialize() override;
  UserServer(const Username &username, uint32_t score);

  std::vector<UserServer> GetFriendsWithoutLoadingTheirFriends();

private:
  static std::unique_ptr<std::vector<UserServer>>
  UsersVectorFromUsersStringVector(
      const std::vector<std::vector<std::string>> &users_string_vector);

  UserServer(const std::vector<std::string> &database_query_result);
  UserServer(const std::string &username, const std::string &password, uint32_t score);
};

#endif // QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_SERVER_H_