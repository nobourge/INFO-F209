
#include "game_mode_selection_menu_view_controller.h"

GameModeSelectionMenuViewController::GameModeSelectionMenuViewController()
    : MenuViewController(std::make_shared<GameModeSelectionMenuView>()){}