//
// Created by guest on 01/03/2022.
//

#include "game_view_controller.h"
#include "../views/menu_views/game_view.h"
#include "../views/menu_views/help_menu_view.h"
#include "../views/menu_views/views/label.h"

GameViewController::GameViewController()
    : AbstractAuthedMenuViewController(std::make_shared<GameView>()) {
  std::shared_ptr<TextField> text_field_ =
      std::make_shared<TextField>(GetMenuView().get(), "", this);
  text_field_->SetPlaceholder("Move:");
  GetMenuView()->UpdateSubviews({
      text_field_,
  });
}

void GameViewController::TextChanged(TextField &sender,
                                     const std::string &old_text) {}
void GameViewController::TextEditingFinished(TextField &sender) {
  sender.SetInnerText("");
}