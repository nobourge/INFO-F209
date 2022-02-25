//
// Created by Anton Romanova on 25/02/2022.
//

#ifndef QUORIDOR_SRC_COMMON_UTILS_H_
#define QUORIDOR_SRC_COMMON_UTILS_H_

#include <chrono>

#define GET_UNIX_TIMESTAMP std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count()

#endif //QUORIDOR_SRC_COMMON_UTILS_H_
