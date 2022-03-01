
#include "game_mode_selection_menu_view_controller.h"

GameModeSelectionMenuViewController::GameModeSelectionMenuViewController()
    : AbstractAuthedMenuViewController(std::make_shared<GameModeSelectionMenuView>()){}