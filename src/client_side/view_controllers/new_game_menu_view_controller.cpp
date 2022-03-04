
#include "new_game_menu_view_controller.h"

NewGameMenuViewController::NewGameMenuViewController()
    : AbstractAuthedMenuViewController(std::make_shared<NewGameMenuView>()){}