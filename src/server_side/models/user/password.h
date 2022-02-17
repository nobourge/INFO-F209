//
// Created by Anton Romanova on 17/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_PASSWORD_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_PASSWORD_H_

#include <string>
#include "abstract_validator.h"

class PasswordValidator: public AbstractValidator {
  ValidatorResult Validate(const std::string &value) override;
};

class Password {

 private:
  std::string hash_;
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_PASSWORD_H_
