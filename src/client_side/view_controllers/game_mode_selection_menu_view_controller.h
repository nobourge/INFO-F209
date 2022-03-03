#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_GAME_MODE_SELECTION_MENU_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_GAME_MODE_SELECTION_MENU_VIEW_CONTROLLER_H_

#include "../views/menu_views/game_mode_selection_menu_view.h"
#include "abstract_authed_menu_view_controller.h"
#include "ncurses.h"
#include <string>


class GameModeSelectionMenuViewController : public AbstractAuthedMenuViewController {
 public:
   GameModeSelectionMenuViewController();
};



#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_GAME_MODE_SELECTION_MENU_VIEW_CONTROLLER_H_