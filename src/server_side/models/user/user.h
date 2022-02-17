//
// Created by Anton Romanova on 17/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_H_

#include "username.h"
#include "../serializable.h"
class User : public Serializable {
 public:
  User(const Username &username);
  std::unique_ptr<crow::json::wvalue> Serialize() override;
  [[nodiscard]] const Username &GetUsername() const;
  [[nodiscard]] int64_t GetCreationTimestamp() const;
 private:
  Username username_;
  int64_t creation_timestamp_;
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_H_
