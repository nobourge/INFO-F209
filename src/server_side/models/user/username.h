//
// Created by Anton Romanova on 17/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_USERNAME_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_USERNAME_H_

#include "abstract_validator.h"
#include <exception>

struct InvalidUsername : public std::exception {
  [[nodiscard]] const char *what() const noexcept override;
  ///
  /// \param validation_error_description
  InvalidUsername(std::string validation_error_description);
 private:
  std::string error_message_;
};


struct UsernameValidator : public AbstractValidator {
 public:
    ///
    /// \param value
    /// \return
  ValidatorResult Validate(const std::string &value) override;
};

class Username {
 public:
    ///
    /// \param username
    /// \return
    static bool IsValid(const std::string &username);

    ///
    /// \param value
    explicit Username(std::string value);
    ///
    /// \return
    [[nodiscard]] const std::string &GetValue() const;

 private:
    std::string value_;
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_USERNAME_H_
