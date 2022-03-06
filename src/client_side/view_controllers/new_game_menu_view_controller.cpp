
#include "new_game_menu_view_controller.h"
#include "../models/api_wrapper.h"
#include "../views/menu_views/views/label.h"

NewGameMenuViewController::NewGameMenuViewController()
    : AbstractAuthedMenuViewController(std::make_shared<NewGameMenuView>()) {
  title_field_ = std::make_shared<TextField>(GetMenuView().get(), "", this);
  title_field_->SetPlaceholder("Title:");

  opponent_username_field_ =
      std::make_shared<TextField>(GetMenuView().get(), "", this);
  opponent_username_field_->SetPlaceholder("Username:");
}

void NewGameMenuViewController::TextChanged(TextField &sender,
                                            const std::string &old_text) {}
void NewGameMenuViewController::TextEditingFinished(TextField &sender) {}

void NewGameMenuViewController::CreateGame() {
  if (!title_field_->GetUserEnteredText().empty() &&
      !opponent_username_field_->GetUserEnteredText().empty()) {
    auto err = ApiWrapper::GetShared()->CreateGame(
        title_field_->GetUserEnteredText(),
        opponent_username_field_->GetUserEnteredText());
    notification_message_ =
        err.has_value() ? err->error_message : "Successfully created";
    ReloadSubviews();
  }
}

void NewGameMenuViewController::ReloadSubviews() {
  auto menu_ptr = GetMenuView().get();

  if (notification_message_.has_value()) {
    GetMenuView()->UpdateSubviews(
        { std::make_shared<Label>(menu_ptr, *notification_message_) });
  } else {
    GetMenuView()->UpdateSubviews(
        {std::make_shared<Label>(menu_ptr, "Game title?"), title_field_,
         std::make_shared<Label>(menu_ptr, ""),
         std::make_shared<Label>(menu_ptr, "Opponent Username?"),
         opponent_username_field_,
         std::make_shared<Button>(menu_ptr, "Create",
                                  [&]() { CreateGame(); })});
  }
}
void NewGameMenuViewController::MenuViewWillAppear() {
  notification_message_ = {};
  ReloadSubviews();
  AbstractAuthedMenuViewController::MenuViewWillAppear();
}
