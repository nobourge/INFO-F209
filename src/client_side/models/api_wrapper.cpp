//
// Created by Anton Romanova on 26/02/2022.
//

#include "api_wrapper.h"
#include "requests.h"
#include <stdexcept>

ApiWrapper::ApiWrapper() {

}
std::unique_ptr<std::vector<User>> ApiWrapper::GetUsersRanked(unsigned int max_num_users) {
  std::string url = url_;
  url += "users/ranking?max_num_users=";
  url += std::to_string(max_num_users);
//  std::cout << Requests(url, {}).GetJson() << std::endl;
  auto json_res = Requests(url, {}).GetJson();
  auto users_json = json_res["users"];

  auto users = std::make_unique<std::vector<User>>();
  users->reserve(users->size());
  for (auto &user_json : users_json) {
    users->push_back(User(user_json));
  }
  return users;
}
