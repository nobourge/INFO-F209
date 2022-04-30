//
// Created by Anton Romanova on 28/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_SERVER_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_SERVER_H_

#include "user/message.h"
#include "user/user.h"
#include "../utils.h"
#include "Game.h"
#include "database.h"

class UserServer : public User, public Serializable {
public:
  bool SaveToDB();

  static std::optional<UserServer>
  InitFromDbByIdWithoutFriendList(object_id_t id);

  static std::optional<UserServer>
  InitFromDB(const Username &username,
             const std::optional<std::string> &password = {});

  static std::optional<UserServer> NewUser(const Username &username,
                                           const std::string &password);

  static std::unique_ptr<std::vector<UserServer>>
  GetAllObjectsFromDB();

  std::unique_ptr<std::vector<UserServer>>
  GetAllObjectsFromDBExceptCurrentUser();

  static std::unique_ptr<std::vector<UserServer>>
  GetRankingFromDB(int max_num_users);

  crow::json::wvalue Serialize() override;
  UserServer(const Username &username, uint32_t score);

  void AddFriendAndSaveToDb(const UserServer &user);

  std::vector<Message>
  RetrieveMessagesWithUserFromDb(const UserServer &other_user);

  bool SendMessageAndSaveToDb(const UserServer &receiver,
                              const std::string &message);

  std::vector<UserServer> GetFriendsWithoutLoadingTheirFriends();

//  std::optional<object_id_t>
//  CreateNewGameAndSaveToDb(const std::vector<UserServer> &invitees,
//                           const std::string &room_name) {
//    // it is possible to have at most 3 invitees. If there are only two, an AI
//    // player will be added
//    if (invitees.size() <= 3) {
//      auto game = Game(room_name);
//      auto game_id = DataBase::GetInstance()->CreateGame(GetId(), room_name,
//                                                         <#initializer #>);
//      for (auto &invitee : invitees)
//        DataBase::GetInstance()->InviteUserToGame(game_id, invitee.GetId());
//      return game_id;
//    } else
//      return {};
//  }

private:
  static std::unique_ptr<std::vector<UserServer>>
  UsersVectorFromUsersStringVector(
      const std::vector<std::vector<std::string>> &users_string_vector);

  UserServer(const std::vector<std::string> &database_query_result);
};

#endif // QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_SERVER_H_
