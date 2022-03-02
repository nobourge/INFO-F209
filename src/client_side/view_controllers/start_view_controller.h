#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_START_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_START_VIEW_CONTROLLER_H_

#include "../views/menu_views/start_menu_view.h"
#include "abstract_menu_view_controller.h"
#include "ncurses.h"
#include <string>


class StartViewController : public AbstractMenuViewController {
 public:
  StartViewController();
};



#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_START_VIEW_CONTROLLER_H_