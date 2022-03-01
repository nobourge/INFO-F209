//
// Created by Anton Romanova on 17/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_PASSWORD_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_PASSWORD_H_

#include <string>
#include "abstract_validator.h"

struct PasswordValidator: public AbstractValidator {
  ValidatorResult Validate(const std::string &value) override;
};

struct InvalidPasswordError : public std::exception {
  [[nodiscard]] const char *what() const noexcept override;
  InvalidPasswordError(std::string validation_error_description);
private:
  std::string error_message_;
};


class Password {
public:
  Password();
  explicit Password(std::string value);

  static bool IsValid(const std::string &password);

  [[nodiscard]] const std::string &GetValue() const;

private:
  std::string value_;
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_PASSWORD_H_
