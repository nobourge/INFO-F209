#include <string>

#ifndef INFO_F209_SRC_CLIENT_SIDE_ABSTRACT_CONTROLLER_H_
#define INFO_F209_SRC_CLIENT_SIDE_ABSTRACT_CONTROLLER_H_

class AbstractController {
 public:
  virtual std::string Control()=0;
};

#endif //INFO_F209_SRC_CLIENT_SIDE_ABSTRACT_CONTROLLER_H_
