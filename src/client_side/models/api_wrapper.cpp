//
// Created by Anton Romanova on 26/02/2022.
//

#include "api_wrapper.h"
#include "requests.h"
#include <stdexcept>

std::vector<UserClient> ApiWrapper::GetUsersRanked(unsigned int max_num_users) {
  std::string url = url_;
  url += "users/ranking?max_num_users=";
  url += std::to_string(max_num_users);
  //  std::cout << Requests(url, {}).GetJson() << std::endl;
  auto json_res = Requests(url, {}).GetJson();
  crow::json::rvalue users_json;
  try {
    users_json = json_res["users"];
  } catch (const std::runtime_error &) {
    return {};
  }

  auto users = std::vector<UserClient>();
  users.reserve(users.size());
  for (auto &user_json : users_json) {
    users.push_back(UserClient(user_json));
  }
  return users;
}

static std::string ReceiveNewMessages(int id){
  return "wip";
}

ApiWrapper::ApiWrapper(const std::string &login, const std::string &password)
    : login_(login), password_(password) {}

std::variant<UserClient, LoginError> ApiWrapper::GetCurrentUser() {
  std::string url = url_;
  url += "me";

  std::variant<UserClient, LoginError> ret =
      LoginError{"A network error occurred"};
  crow::json::rvalue request_result_json;

  try {
    request_result_json = Requests(url, {{login_, password_}}).GetJson();
  } catch (const std::runtime_error &) {
    return ret;
  }

//  try {
//    ret = UserClient(request_result_json);
//  } catch (const std::runtime_error &) {
//    ret = LoginError{{request_result_json["error"]}};
//  }
  return ret;
}

std::variant<ApiWrapper, LoginError>
ApiWrapper::Login(const std::string &login, const std::string &password) {
  auto api_wrapper = ApiWrapper(login, password);

  auto user = api_wrapper.GetCurrentUser();

  if (holds_alternative<LoginError>(user)) {
    return std::get<LoginError>(user);
  } else {
    return api_wrapper;
  }
}
void ApiWrapper::SendNewMessages(std::string message) {

}


