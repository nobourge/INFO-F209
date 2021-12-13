//
// Created by Anton Romanova on 11/12/2021.
//

#ifndef QUORIDOR_SERVER_SIDE_PLATFORM_USERNAME_H_
#define QUORIDOR_SERVER_SIDE_PLATFORM_USERNAME_H_

#include "abstract_validator.h"
#include <string>

class Username: AbstractValidator {
 public:
  [[nodiscard]] const std::string &GetValue() const;
  void SetValue(const std::string &value) {
    if (IsValid(value)) {
      value_ = value;
    } else {
      //TODO: correct exception handling with throw
      exit(1);
    }
  }
  bool IsValid(const std::string &value_to_validate) const;
 protected:
  std::regex GetRegex() const;
 private:
  std::string value_;
};

#endif //QUORIDOR_SERVER_SIDE_PLATFORM_USERNAME_H_
