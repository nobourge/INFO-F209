//
// Created by Anton Romanova on 04/03/2022.
//

#include "join_or_create_game_menu_view.h"
#include "../../view_controllers/view_controller_menu_new_game.h"
#include "../../view_controllers/view_controller_menu_join_game.h"

JoinOrCreateGameMenuView::JoinOrCreateGameMenuView()
    : AbstractMenuView(menu_name) {
  UpdateSubviews({
      std::make_shared<MenuButtonItem>(
          this, "New game", std::make_shared<NewGameMenuViewController>(),
          this),

      std::make_shared<MenuButtonItem>(
          this, "Join existing",
          std::make_shared<JoinGameMenuViewController>(), this),
  });
}
