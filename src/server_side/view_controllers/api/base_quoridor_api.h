//
// Created by Anton Romanova on 14/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_BASE_QUORIDOR_API_H_
#define QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_BASE_QUORIDOR_API_H_

#include "../../../includes/crow_all.hpp"
#include "../../../common/constants.h"
#include <functional>

class BaseQuoridorApi {
 public:
  static const unsigned kQuoridorApiVersion;
  BaseQuoridorApi();

  void Run();

 protected:
  [[nodiscard]] crow::SimpleApp &GetApp();
  virtual void SetupRoutes();
 private:
  crow::SimpleApp app{};
};



#endif //QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_BASE_QUORIDOR_API_H_
