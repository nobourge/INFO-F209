//
// Created by Anton Romanova on 11/12/2021.
//

#ifndef QUORIDOR_SERVER_SIDE_PLATFORM_VALIDATORS_ABSTRACT_VALIDATOR_H_
#define QUORIDOR_SERVER_SIDE_PLATFORM_VALIDATORS_ABSTRACT_VALIDATOR_H_

#include <string>
#include <regex>

class AbstractValidator {
 public:
  virtual ~AbstractValidator() = default;
  virtual bool IsValid(const std::string &value_to_validate) const = 0;
 protected:
  virtual std::regex GetRegex() const = 0;
};

#endif //QUORIDOR_SERVER_SIDE_PLATFORM_VALIDATORS_ABSTRACT_VALIDATOR_H_
