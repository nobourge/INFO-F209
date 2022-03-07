//
// Created by Anton Romanova on 04/03/2022.
//

#include "view_controller_menu_join_or_create_game.h"
#include "../views/menu_views/join_or_create_game_menu_view.h"

JoinOrCreateGameMenuViewController::JoinOrCreateGameMenuViewController()
    : AbstractMenuViewController(std::make_shared<JoinOrCreateGameMenuView>()) {
}
