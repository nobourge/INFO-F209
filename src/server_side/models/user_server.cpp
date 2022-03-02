//
// Created by Anton Romanova on 28/02/2022.
//

#include "user_server.h"
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
    : User(std::stoull(query_res[0]), Username{query_res[1]}, query_res[2],
           std::stoll(query_res[3]), std::stoul(query_res[4]), {}) {}

std::unique_ptr<std::vector<UserServer>>
UserServer::GetRankingFromDB(int max_num_users) {
  return UsersVectorFromUsersStringVector(DataBase::GetInstance()->GetSelect(
      "SELECT * FROM USER ORDER BY USER.SCORE DESC LIMIT " +
      std::to_string(max_num_users)));
}

std::optional<UserServer>
UserServer::InitFromDB(const Username &username, const std::optional<std::string> &password) {
  auto users_string_vector = DataBase::GetInstance()->GetSelect(
      "SELECT * FROM USER WHERE USER.PSEUDO=\"" + username.GetValue() + "\"");

  if (users_string_vector.empty()) {
    return {};
  } else if (users_string_vector.size() > 1) {
    throw std::runtime_error("Two users with same username in database");
  } else {
    auto user = UserServer(users_string_vector[0]);

    if (password.has_value()) {
      if (user.GetPassword() != password) {
        return {};
      }
    }

    user.SetFriendsIds(DataBase::GetInstance()->SearchFriends(user.GetId()));

    return user;
  }
}

bool UserServer::SaveToDB() {
  auto users_with_same_id = DataBase::GetInstance()->GetSelect(
      "SELECT * FROM USER WHERE USER.PSEUDO=" + GetUsername().GetValue());

  if (users_with_same_id.empty()) {
    // the user does not exist
    return false;
  } else {
    // save new score
    DataBase::GetInstance()->UpdateUser(GetScore(), GetId());

    auto friends_in_db = DataBase::GetInstance()->SearchFriends(GetId());
    if (friends_in_db != GetFriendsIds()) {
      // update friends list

      std::unordered_set<object_id_t> friends_changes = {};

      std::set_difference(
          friends_in_db.begin(), friends_in_db.end(),
          GetFriendsIds().begin(), GetFriendsIds().end(),
          std::inserter(friends_changes, friends_changes.end()));
      for (auto &changed_friend : friends_changes) {
        if (GetFriendsIds().contains(changed_friend)) {
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


  crow::json::wvalue friends_json;

  {
    auto friends = GetFriendsWithoutLoadingTheirFriends();
    for (int i = 0; i < friends.size(); i++) {
      friends_json[i] = std::move(*friends[i].Serialize());
    }
  }

  (*json_output)["friends"] = std::move(friends_json);
  return json_output;
}

UserServer::UserServer(const Username &username, uint32_t score)
    : User(username, {}, score) {}


std::optional<UserServer> UserServer::NewUser(const Username &username,
                                              const string &password) {
  // check if there is any user with same username in db
  auto users_with_same_username = InitFromDB(username);
  if (users_with_same_username.has_value()) {
    return {};
  }
//  DataBase::GetInstance()->GetSelect(R"(INSERT INTO USER (PSEUDO, PASSWORD, TIMESTAMP, SCORE) VALUES ("test55", "haha", 5, 100);)");
  DataBase::GetInstance()->InsertPlayer(username.GetValue(), password, GET_UNIX_TIMESTAMP, 0);
  return UserServer::InitFromDB(username);
}

std::optional<UserServer> UserServer::InitFromDbByIdWithoutFriendList(const uint32_t id) {
  auto users_string_vector = DataBase::GetInstance()->GetSelect(
      "SELECT * FROM USER WHERE USER.ID=" + std::to_string(id));

  if (users_string_vector.empty()) {
    return {};
  } else {
    return UserServer(users_string_vector[0]);
  }
}

std::vector<UserServer> UserServer::GetFriendsWithoutLoadingTheirFriends() {
  std::vector<UserServer> output;

  for (const auto &friend_id : GetFriendsIds()) {
    auto friend_user = UserServer::InitFromDbByIdWithoutFriendList(friend_id);
    if (friend_user.has_value()) {
      output.push_back(std::move(*friend_user));
    } else {
      // TODO: delete friend relation, the user does not exist
    }
  }
  return output;
}

bool UserServer::AddFriendAndSaveToDb(const UserServer &user) {

  DataBase::GetInstance()->InsertFriend(GetId(), user.GetId());
}
