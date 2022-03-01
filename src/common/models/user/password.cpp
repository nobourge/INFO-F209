//
// Created by Anton Romanova on 17/02/2022.
//

#include "password.h"
#include "../../constants.h"
#include <vector>

/// check input password conformity
/// \param value
/// \return

ValidatorResult PasswordValidator::Validate(const std::string &value) {
  static std::vector<char> valid_special_chars = {'-', '_'};
  if (value.size() < MIN_PASSWORD_LENGTH) {
    return ValidatorResult{"Password too short"};
  } else if (value.size() > MAX_PASSWORD_LENGTH) {
    return ValidatorResult{"Password too long"};
  } else if (!AbstractValidator::AreCharactersValid(value)) {
    return ValidatorResult{"Password contains at least one invalid character"};
  }
  return {};
}

const char *InvalidPasswordError::what() const noexcept {
  return error_message_.c_str();
}

InvalidPasswordError::InvalidPasswordError(
    std::string validation_error_description) {
  error_message_ = std::move(validation_error_description);
}

Password::Password() : value_(){}

Password::Password(std::string value) {
  auto username_validation_res = PasswordValidator().Validate(value);
  if (!username_validation_res.IsValid()) {
    throw InvalidPasswordError(username_validation_res.GetErrorMessage());
  }
  value_ = std::move(value);
}


bool Password::IsValid(const std::string &password) {
  return PasswordValidator().Validate(password).IsValid();
}

const std::string &Password::GetValue() const {
  return value_;
}
