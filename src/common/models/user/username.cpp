//
// Created by Anton Romanova on 17/02/2022.
//

#include "username.h"
#include "../../constants.h"

#include <utility>
#include <vector>



ValidatorResult UsernameValidator::Validate(const std::string &value) {
  if (value.size() < MIN_USERNAME_SIZE) {
    return ValidatorResult{"Username too short"};
  } else if (value.size() > MAX_USERNAME_SIZE) {
    return ValidatorResult{"Username too long"};
  } else if (!AbstractValidator::AreCharactersValid(value)) {
    return ValidatorResult{"Username contains at least one invalid character"};
  }
  return {};
}

bool Username::IsValid(const std::string &username) {
  return UsernameValidator().Validate(username).IsValid();
}

const std::string &Username::GetValue() const { return value_; }

Username::Username(std::string value) {
  auto username_validation_res = UsernameValidator().Validate(value);
  if (!username_validation_res.IsValid()) {
    throw InvalidUsernameError(username_validation_res.GetErrorMessage());
  }
  value_ = std::move(value);
}

Username::Username() : value_() {}

const char *InvalidUsernameError::what() const noexcept {
  return error_message_.c_str();
}

InvalidUsernameError::InvalidUsernameError(
    std::string validation_error_description)
    : error_message_(std::move(validation_error_description)) {}
