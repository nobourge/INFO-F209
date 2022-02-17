//
// Created by Anton Romanova on 17/02/2022.
//

#include "abstract_validator.h"

#include <utility>

bool ValidatorResult::IsValid() const {
  return !error_message_.has_value();
}

std::string ValidatorResult::GetErrorMessage() const {
  return error_message_.value_or("");
}

ValidatorResult::ValidatorResult(std::optional<std::string> error_message) : error_message_(std::move(error_message)) {}
ValidatorResult::ValidatorResult() {}
