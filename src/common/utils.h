//
// Created by Anton Romanova on 25/02/2022.
//

#ifndef QUORIDOR_SRC_COMMON_UTILS_H_
#define QUORIDOR_SRC_COMMON_UTILS_H_

#include <chrono>

#define GET_TIME_SINCE_EPOCH std::chrono::system_clock::now().time_since_epoch()
#define GET_UNIX_TIMESTAMP std::chrono::duration_cast<std::chrono::seconds>(GET_TIME_SINCE_EPOCH).count()
#define GET_TIME_IN_MILLIS std::chrono::duration_cast<std::chrono::milliseconds>(GET_TIME_SINCE_EPOCH).count();


#endif //QUORIDOR_SRC_COMMON_UTILS_H_
