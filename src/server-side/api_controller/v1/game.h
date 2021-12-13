//
// Created by Anton Romanova on 10/12/2021.
//

#ifndef QUORIDOR_SERVER_SIDE_API_V1_GAME_H_
#define QUORIDOR_SERVER_SIDE_API_V1_GAME_H_

#include "user.h"
#include <optional>
#include <memory>

class APIGame {
  static std::optional<std::shared_ptr<APIGame>> New(const std::vector<std::shared_ptr<APIUser>> &opponents);
  bool join();
};

#endif //QUORIDOR_SERVER_SIDE_API_V1_GAME_H_
