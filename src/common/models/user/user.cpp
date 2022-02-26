//
// Created by Anton Romanova on 17/02/2022.
//

#include "user.h"
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

// void User::SaveToDB() {
//
// }

void User::NewFriend(const User &new_friend) {}

User::User()
    : id_(0), username_(), creation_timestamp_(GET_UNIX_TIMESTAMP), score_(0) {}

User::User(const crow::json::rvalue &json)
    : id_(static_cast<int>(json["id"])),
      username_(Username{json["username"].s()}),
      creation_timestamp_(static_cast<int>(json["created_timestamp"])),
      score_(static_cast<int>(json["score"])) {

}

// User &User::InitFromDB(object_id_t id) {
//   return *this;
// }
