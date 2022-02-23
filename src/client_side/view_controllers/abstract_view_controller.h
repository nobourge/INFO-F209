#include <string>
#include <optional>
#include <memory>

#ifndef INFO_F209_SRC_CLIENT_SIDE_ABSTRACT_CONTROLLER_H_
#define INFO_F209_SRC_CLIENT_SIDE_ABSTRACT_CONTROLLER_H_

class AbstractViewController {
 public:
  virtual std::optional<std::shared_ptr<AbstractViewController>> Tick() = 0;
  virtual void RespondToKeyboardEvent(const int &character) = 0;
};

#endif //INFO_F209_SRC_CLIENT_SIDE_ABSTRACT_CONTROLLER_H_
