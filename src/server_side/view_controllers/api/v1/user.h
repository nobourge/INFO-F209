//
// Created by Anton Romanova on 15/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_USER_H_
#define QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_USER_H_

#include "../base_api_module.h"

template<typename ...Middlewares>
class User: public BaseApiModule<Middlewares...>{
 public:
  void SetupRoutes(const std::string &base_url, crow::Crow<Middlewares...> &app) override {
    BaseApiModule<Middlewares...>::SetupRoutes(base_url, app);

  }
};

#endif //QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_USER_H_
