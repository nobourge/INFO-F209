#include "../views/menu_views/home_menu_view.h"
#include "menu_view_controller.h"
#include "ncurses.h"
#include <string>

#ifndef QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_

class HomeMenuViewController : public MenuViewController {
 public:
  HomeMenuViewController();
};

//class ControllerLoginClient : public AbstractViewController {
// public:
//  std::shared_ptr<AbstractViewController> Tick();
//};

#endif //QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_
