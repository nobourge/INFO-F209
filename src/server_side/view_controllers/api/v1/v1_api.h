//
// Created by Anton Romanova on 15/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_
#define QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_

#include "../base_quoridor_api.h"
#include "../base_api_module.h"

template<class ...Middlewares>
class V1Api : public BaseQuoridorApi, public BaseApiModule<Middlewares...> {
 public:
 protected:
 public:
  void SetupRoutes(const std::string &base_url, crow::Crow<Middlewares...> &app) override {
    BaseApiModule<Middlewares...>::SetupRoutes(base_url, app);
  }
 protected:
  void SetupRoutes() override {
    BaseQuoridorApi::SetupRoutes();
//    SetupRoutes()
  }
 private:
 public:
  [[nodiscard]] unsigned int GetVersion() const;
 private:
  const unsigned version_ = 0;
};



#endif //QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_
