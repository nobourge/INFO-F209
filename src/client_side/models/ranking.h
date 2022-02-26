//
// Created by Anton Romanova on 26/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_MODELS_RANKING_H_
#define QUORIDOR_SRC_CLIENT_SIDE_MODELS_RANKING_H_

#include <memory>
#include <vector>
#include <curl/curl.h>
#include "../../common/models/user/user.h"
#include "../../common/constants.h"
#include "../../includes/crow_all.hpp"

struct Ranking {
  static std::unique_ptr<std::vector<User>> GetUsersRanking(int max_num_users = MAX_NUM_USERS_RANKING_DEFAULT) {

  }
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_MODELS_RANKING_H_
