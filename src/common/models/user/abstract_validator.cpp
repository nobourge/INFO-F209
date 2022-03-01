//
// Created by Anton Romanova on 17/02/2022.
//

#include "abstract_validator.h"

#include <utility>

///
/// \return
bool ValidatorResult::IsValid() const {
  return !error_message_.has_value();
}

///
/// \return
std::string ValidatorResult::GetErrorMessage() const {
  return error_message_.value_or("");
}

ValidatorResult::ValidatorResult(std::optional<std::string> error_message) : error_message_(std::move(error_message)) {}


ValidatorResult::ValidatorResult() {}


bool AbstractValidator::AreCharactersValid(const std::string &value) {
  static const std::vector<char> kValidSpecialChars = VALID_SPECIAL_CHARS;
  return std::all_of(value.begin(), value.end(), [](const char &c) {
    return std::isalnum(c) or
        (std::find(kValidSpecialChars.begin(), kValidSpecialChars.end(), c)
            != kValidSpecialChars.end());
  });
}
