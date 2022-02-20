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
  ///
  /// \return
  std::unique_ptr<crow::json::wvalue> Serialize() override;
  ///
  /// \return
  [[nodiscard]] const Username &GetUsername() const;
  ///
  /// \return
  [[nodiscard]] int64_t GetCreationTimestamp() const;
 private:
  Username username_;
  int64_t creation_timestamp_;
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_H_
