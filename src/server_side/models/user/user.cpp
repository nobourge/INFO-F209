//
// Created by Anton Romanova on 17/02/2022.
//

#include "user.h"

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

  return json_output;
}

///
/// \param username
User::User(const Username &username) :
username_(username),
creation_timestamp_(std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()).count()){

}

///
/// \return
int64_t User::GetCreationTimestamp() const {
  return creation_timestamp_;
}
