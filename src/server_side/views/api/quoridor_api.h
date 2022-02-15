//
// Created by Anton Romanova on 14/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_QUORIDOR_API_H_
#define QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_QUORIDOR_API_H_

#include "../../../includes/crow_all.hpp"
#include "constants.h"

class QuoridorAPI {
 public:
  static const unsigned kQuoridorApiVersion;
  [[nodiscard]] const crow::SimpleApp &GetApp() const;
  QuoridorAPI();

  void Run();

 protected:
  void SetupRoutes();
 private:
  crow::SimpleApp app{};
};



#endif //QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_QUORIDOR_API_H_
