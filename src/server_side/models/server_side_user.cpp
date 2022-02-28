//
// Created by Anton Romanova on 28/02/2022.
//

#include "server_side_user.h"
#include "../../common/utils.h"
#include "database.h"

std::unique_ptr<std::vector<UserServer>>
UserServer::UsersVectorFromUsersStringVector(
    const std::vector<std::vector<std::string>> &users_string_vector) {
  auto users = std::make_unique<std::vector<UserServer>>();

  users->reserve(users_string_vector.size());
  for (auto &user_string_vector : users_string_vector) {
    users->push_back(UserServer(user_string_vector));
  }

  return users;
}

std::unique_ptr<std::vector<UserServer>> UserServer::GetAllObjectsFromDB() {
  return UsersVectorFromUsersStringVector(
      DataBase::GetInstance()->GetSelect("SELECT * FROM USER"));
}

UserServer::UserServer(const vector<std::string> &query_res)
    : User(std::stoul(query_res[0]), Username{query_res[1]}, GET_UNIX_TIMESTAMP,
           std::stoul(query_res[4]),
           std::make_unique<std::unordered_set<object_id_t>>()) {}

std::unique_ptr<std::vector<UserServer>>
UserServer::GetRankingFromDB(int max_num_users) {
  return UsersVectorFromUsersStringVector(DataBase::GetInstance()->GetSelect(
      "SELECT * FROM USER ORDER BY USER.SCORE DESC LIMIT " +
      std::to_string(max_num_users)));
}

std::optional<std::unique_ptr<UserServer>>
UserServer::InitFromDB(const Username &username) {
  auto users_string_vector = DataBase::GetInstance()->GetSelect(
      "SELECT * FROM USER WHERE USER.PSEUDO=\"" + username.GetValue() + "\"");

  if (users_string_vector.empty()) {
    return {};
  } else if (users_string_vector.size() > 1) {
    throw std::runtime_error("Two users with same username in database");
  } else {
    auto user =
        std::unique_ptr<UserServer>(new UserServer(users_string_vector[0]));

    user->SetFriendsIds(DataBase::GetInstance()->SearchFriends(user->GetId()));

    return user;
  }
}

bool UserServer::SaveToDB() {
  auto users_with_same_id = DataBase::GetInstance()->GetSelect(
      "SELECT * FROM USER WHERE USER.ID=" + std::to_string(GetId()));

  if (users_with_same_id.empty()) {
    // register new user

    // check if there is any user with same username in db
    auto users_with_same_username = InitFromDB(GetUsername());
    if (users_with_same_username.has_value()) {
      return false;
    }

    DataBase::GetInstance()->InsertPlayer(GetId(), GetUsername().GetValue(), "",
                                          GetCreationTimestamp(), GetScore());
    return true;
  } else {
    // save new score
    DataBase::GetInstance()->UpdateUser(GetScore(), GetId());

    auto friends_in_db = DataBase::GetInstance()->SearchFriends(GetId());
    if (*friends_in_db != *GetFriendsIds()) {
      // update friends list

      std::unordered_set<object_id_t> friends_changes = {};

      std::set_difference(
          friends_in_db->begin(), friends_in_db->end(),
          GetFriendsIds()->begin(), GetFriendsIds()->end(),
          std::inserter(friends_changes, friends_changes.end()));
      for (auto &changed_friend : friends_changes) {
        if (GetFriendsIds()->contains(changed_friend)) {
          // the friend was added
          DataBase::GetInstance()->InsertFriend(GetId(), changed_friend);
        } else {
          // the friend was removed
          // TODO: REMOVE FRIEND
        }
      }
    }

    return true;
  }
}

std::unique_ptr<crow::json::wvalue> UserServer::Serialize() {
  auto json_output = std::make_unique<crow::json::wvalue>();

  (*json_output)["id"] = GetId();
  (*json_output)["username"] = GetUsername().GetValue();
  (*json_output)["created_timestamp"] = GetCreationTimestamp();
  (*json_output)["score"] = GetScore();

  return json_output;
}
UserServer::UserServer(const Username &username, uint32_t score)
    : User(username, score) {}
