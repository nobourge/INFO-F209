#include "view/MainMenuView.h"
#include "main_menu.hpp"
#include "ncurses.h"
#include <string>
#include "abstract_controller.h"
#include "enum_factory.h"


#ifndef QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_

class ControllerMainMenu:public AbstractController{
 public:
  int Control();
};

class ControllerLoginClient :public AbstractController{
 public:
  int Control();
};



#endif //QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_
