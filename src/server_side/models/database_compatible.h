//
// Created by Anton Romanova on 25/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_DATABASE_COMPATIBLE_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_DATABASE_COMPATIBLE_H_

#include <memory>
#include "../../common/constants.h"

template<typename T>
struct DatabaseCompatible {
  virtual void SaveToDB() = 0;
  virtual T & InitFromDB(object_id_t id) = 0;
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_DATABASE_COMPATIBLE_H_
