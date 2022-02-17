#include "view/MainMenuView.h"
#include "main_menu.hpp"
#include "ncurses.h"
#include <string>
#include "abstract_controller.h"

#ifndef QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_

class ControllerMainMenu:public AbstractController{
 public:
  std::string Control();
};

class ControllerLoginClient :public AbstractController{
 public:
  std::string Control();
};



#endif //QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_
