#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_WELCOME_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_WELCOME_H_

#include "../views/menu_views/start_menu_view.h"
#include "view_controller_menu_abstract.h"
#include "ncurses.h"
#include <string>


class StartViewController : public AbstractMenuViewController {
 public:
  StartViewController();
};



#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_WELCOME_H_