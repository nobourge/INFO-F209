//
// Created by Anton Romanova on 17/02/2022.
//

#include "username.h"
#include "../../constants.h"

#include <utility>
#include <vector>

/// checks input username conformity
/// \param value
/// \return
ValidatorResult UsernameValidator::Validate(const std::string &value) {
  if (value.size() < MIN_USERNAME_SIZE) {
    return ValidatorResult{"Username too short"};
  }
  else if (value.size() > MAX_USERNAME_SIZE) {
    return ValidatorResult{"Username too long"};
  } else if (!std::any_of(value.begin(), value.end(), [](const char &c) {
    static std::vector<char> valid_special_chars = USERNAME_VALID_SPECIAL_CHARS;
    return std::isalnum(c)
        or (std::find(valid_special_chars.begin(), valid_special_chars.end(), c) != valid_special_chars.end());
  })) {
    return ValidatorResult{"Username contains an invalid character"};
  }
  return {};
}

/// validates input username conformity
/// \param username
/// \return
bool Username::IsValid(const std::string &username) {
  return UsernameValidator().Validate(username).IsValid();
}

const std::string &Username::GetValue() const {
  return value_;
}

Username::Username(std::string value) {
  auto username_validation_res = UsernameValidator().Validate(value);
  if (!username_validation_res.IsValid()) {
    throw InvalidUsername(username_validation_res.GetErrorMessage());
  }
  value_ = std::move(value);
}
Username::Username() : value_() {}

const char *InvalidUsername::what() const noexcept {
  return error_message_.c_str();
}

InvalidUsername::InvalidUsername(std::string validation_error_description) : error_message_(
    "Uncaught invalid username usage" + std::move(validation_error_description)
) {

}
