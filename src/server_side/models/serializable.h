//
// Created by Anton Romanova on 17/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_SERIALIZABLE_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_SERIALIZABLE_H_

#include "../../includes/crow_all.hpp"

struct Serializable {
  virtual std::unique_ptr<crow::json::wvalue> Serialize() = 0;
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_SERIALIZABLE_H_
