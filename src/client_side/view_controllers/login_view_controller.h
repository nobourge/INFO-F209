#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_LOGIN_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_LOGIN_VIEW_CONTROLLER_H_

#include "../views/menu_views/login_menu_view.h"
#include "menu_view_controller.h"
#include "ncurses.h"
#include <string>


class LoginMenuViewController : public MenuViewController {
 public:
  LoginMenuViewController();
};



#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_MENU_VIEW_CONTROLLER_H_