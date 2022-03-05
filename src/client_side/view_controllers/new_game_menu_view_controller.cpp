
#include "new_game_menu_view_controller.h"
#include "../views/menu_views/views/label.h"
#include "../views/menu_views/views/text_field.h"

NewGameMenuViewController::NewGameMenuViewController()
    : AbstractAuthedMenuViewController(std::make_shared<NewGameMenuView>()) {
  auto menu_ptr = GetMenuView().get();

  title_field_ = std::make_shared<TextField>(menu_ptr, "", this);
  title_field_->SetPlaceholder("Title:");

  opponent_username_field_ = std::make_shared<TextField>(menu_ptr, "", this);
  opponent_username_field_->SetPlaceholder("Username:");

  GetMenuView()->UpdateSubviews({
      std::make_shared<Label>(menu_ptr, "Game title?"),
      title_field_,
      std::make_shared<Label>(menu_ptr, ""),
      std::make_shared<Label>(menu_ptr, "Opponent Username?"),
      opponent_username_field_,
  });
}

void NewGameMenuViewController::TextChanged(TextField &sender,
                                            const std::string &old_text) {}
void NewGameMenuViewController::TextEditingFinished(TextField &sender) {}
