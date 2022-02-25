//
// Created by Anton Romanova on 17/02/2022.
//

#include "user.h"
#include "../../../common/utils.h"

///
/// \return
const Username &User::GetUsername() const {
  return username_;
}

///
/// \return
std::unique_ptr<crow::json::wvalue> User::Serialize()
{
  auto json_output = std::make_unique<crow::json::wvalue>();

  (*json_output)["username"] = username_.GetValue();
  (*json_output)["created_timestamp"] = GetCreationTimestamp();
  (*json_output)["score"] = GetScore();

  return json_output;
}

User::User(const Username &username, uint32_t score) :
username_(username),
creation_timestamp_(GET_UNIX_TIMESTAMP), score_(score){

}

int64_t User::GetCreationTimestamp() const {
  return creation_timestamp_;
}

uint32_t User::GetScore() const {
  return score_;
}
object_id_t User::GetId() const {
  return id_;
}

void User::SaveToDB() {

}

void User::NewFriend(const User &new_friend) {

}

User &User::InitFromDB(object_id_t id) {
  return *this;
}

