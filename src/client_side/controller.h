
#include <string>

#ifndef QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_
#include "abstract_controller.h"
class ControllerMainMenu:public AbstractController{
 public:
  std::string Control();
};

#endif //QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_
