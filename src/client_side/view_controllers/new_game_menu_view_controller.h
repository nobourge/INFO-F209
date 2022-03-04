#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_NEW_GAME_MENU_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_NEW_GAME_MENU_VIEW_CONTROLLER_H_

#include "../views/menu_views/new_game_menu_view.h"
#include "abstract_authed_menu_view_controller.h"
#include "ncurses.h"
#include <string>


class NewGameMenuViewController : public AbstractAuthedMenuViewController {
 public:
   NewGameMenuViewController();
};



#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_NEW_GAME_MENU_VIEW_CONTROLLER_H_