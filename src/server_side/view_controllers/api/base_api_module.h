//
// Created by Anton Romanova on 15/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_BASE_API_MODULE_H_
#define QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_BASE_API_MODULE_H_

#include "../../../includes/crow_all.hpp"

template<class ...Middlewares>
class BaseApiModule {
 public:
  virtual void SetupRoutes(const std::string &base_url, crow::Crow<Middlewares...> &app);
 protected:
  BaseApiModule() = default;
  std::vector<BaseApiModule<Middlewares...>> submodules;
};

#endif //QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_BASE_API_MODULE_H_
