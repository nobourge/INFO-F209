//
// Created by Anton Romanova on 17/02/2022.
//

#include "user.h"
#include "../../../server_side/models/database.h"
#include "../../utils.h"

const Username &User::GetUsername() const { return username_; }

std::unique_ptr<crow::json::wvalue> User::Serialize() {
  auto json_output = std::make_unique<crow::json::wvalue>();

  (*json_output)["id"] = GetId();
  (*json_output)["username"] = username_.GetValue();
  (*json_output)["created_timestamp"] = GetCreationTimestamp();
  (*json_output)["score"] = GetScore();

  return json_output;
}

User::User(const Username &username, uint32_t score)
    : username_(username), creation_timestamp_(GET_UNIX_TIMESTAMP),
      score_(score) {}

int64_t User::GetCreationTimestamp() const { return creation_timestamp_; }

uint32_t User::GetScore() const { return score_; }
object_id_t User::GetId() const { return id_; }

void User::NewFriend(const User &new_friend) {}

User::User()
    : id_(0), username_(), creation_timestamp_(GET_UNIX_TIMESTAMP), score_(0) {}

User::User(const crow::json::rvalue &json)
    : id_(static_cast<int>(json["id"])),
      username_(Username{json["username"].s()}),
      creation_timestamp_(static_cast<int>(json["created_timestamp"])),
      score_(static_cast<int>(json["score"])) {}

std::optional<std::unique_ptr<User>>
User::InitFromDB(const Username &username) {
  auto res = DataBase::GetInstance()->GetSelect(
      "SELECT * FROM USER WHERE USER.PSEUDO=\"" + username.GetValue() + "\"");

  if (res.empty()) {
    return {};
  } else if (res.size() > 1) {
    throw std::runtime_error("Two users with same username in database");
  } else {
    return std::unique_ptr<User>(new User(res[0]));
  }
}

bool User::SaveToDB() {
  auto users_with_same_id = DataBase::GetInstance()->GetSelect(
      "SELECT * FROM USER WHERE USER.ID=" + std::to_string(id_));

  if (users_with_same_id.empty()) {
    // register new user

    // check if there is any user with same username in db
    auto users_with_same_username = InitFromDB(username_);
    if (users_with_same_username.has_value()) {
      return false;
    }

    DataBase::GetInstance()->InsertPlayer(id_, username_.GetValue(), "",
                                          creation_timestamp_, score_);
    return true;
  } else {
    // update user

    DataBase::GetInstance()->UpdateUser(score_, id_);
    return true;
  }
}

std::unique_ptr<std::vector<User>> User::GetAllObjectsFromDB() {
  return UsersVectorFromUsersStringVector(
      DataBase::GetInstance()->GetSelect("SELECT * FROM USER"));
}

User::User(const vector<std::string> &query_res)
    : id_(std::stoul(query_res[0])), username_(query_res[1]),
      creation_timestamp_(GET_UNIX_TIMESTAMP),
      score_(std::stoul(query_res[4])) {}

std::unique_ptr<std::vector<User>> User::GetRanking(int max_num_users) {
  return UsersVectorFromUsersStringVector(DataBase::GetInstance()->GetSelect(
      "SELECT * FROM USER ORDER BY USER.SCORE DESC LIMIT " +
      std::to_string(max_num_users)));
}

std::unique_ptr<std::vector<User>> User::UsersVectorFromUsersStringVector(
    const std::vector<std::vector<std::string>> &users_string_vector) {
  auto users = std::make_unique<std::vector<User>>();

  users->reserve(users_string_vector.size());
  for (auto &user_string_vector : users_string_vector) {
    users->push_back(User(user_string_vector));
  }

  return users;
}

// User &User::InitFromDB(object_id_t id) {
//   return *this;
// }
