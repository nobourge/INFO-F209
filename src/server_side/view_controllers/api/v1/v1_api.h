//
// Created by Anton Romanova on 15/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_
#define QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_

#include "../base_quoridor_api.h"
#include "../../../models/user/user.h"

#define V1_API_PREFIX "/api/v1/"
#define API_ROUTE(app, url) app.template route<crow::black_magic::get_parameter_tag(url)>(url)

template<class ...Middlewares>
class V1Api : public BaseQuoridorApi {
 public:

  V1Api() {
    SetupRoutes();
  };

  [[nodiscard]] unsigned int GetVersion() const;
 protected:
  void SetupRoutes() override {
    BaseQuoridorApi::SetupRoutes();

    API_ROUTE(GetApp(), "/api/v1/users") ([] () {
      crow::json::wvalue users;
      std::vector<std::string> dummy_usernames = {"User1", "User2", "User3"};
      for (int i = 0; i < dummy_usernames.size(); i++) {
        users[i] = std::move(*User(Username{dummy_usernames[i]}).Serialize());
      }
      crow::json::wvalue output;
      output["users"] = std::move(users);
      return output;
    });

    API_ROUTE(GetApp(), "/api/v1/users/<string>") ([] (const std::string &username) {
      User user{Username{username}};
      return *user.Serialize();
    });

  }
 private:
  static constexpr const unsigned version_ = 0;
};

#undef V1_API_PREFIX

#endif //QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_
