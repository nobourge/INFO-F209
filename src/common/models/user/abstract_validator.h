//
// Created by Anton Romanova on 17/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_ABSTRACT_VALIDATOR_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_ABSTRACT_VALIDATOR_H_

#include "../../constants.h"
#include <optional>
#include <string>
#include <vector>
#include <algorithm>

class ValidatorResult {
public:
  ///
  /// \param error_message
  explicit ValidatorResult(std::optional<std::string> error_message);
  ValidatorResult();

  [[nodiscard]] bool IsValid() const;
  [[nodiscard]] std::string GetErrorMessage() const;

private:
  std::optional<std::string> error_message_;
};

class AbstractValidator {
public:
  virtual ValidatorResult Validate(const std::string &value) = 0;

  static bool AreCharactersValid(const std::string &value);
};

#endif // QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_ABSTRACT_VALIDATOR_H_
