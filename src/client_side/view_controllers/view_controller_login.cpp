#include "view_controller_login.h"
#include "../views/menu_views/views/label.h"
#include "view_controller_home_menu.h"
#include "../models/api_wrapper.h"

LoginMenuViewController::LoginMenuViewController()
    : AbstractMenuViewController(std::make_shared<LoginMenuView>()) {
  username_field_ = std::make_shared<TextField>(GetMenuView().get(), "", this);
  password_field_ = std::make_shared<TextField>(GetMenuView().get(), "", this);
  login_button_ = std::make_shared<MenuButtonItem>(
      GetMenuView().get(), "Login",
      std::make_shared<HomeMenuViewController>(), this);

  username_field_->SetPlaceholder("empty login");
  password_field_->SetPlaceholder("empty password");
  password_field_->SetDisplayMode(TextField::PASSWORD);

}

void LoginMenuViewController::PresentController(
    const std::optional<std::shared_ptr<AbstractViewController>> &destination,
    MenuButtonItem &sender) {
  if (&sender == login_button_.get()) {
    auto login_res = ApiWrapper::Login(username_field_->GetUserEnteredText(), password_field_->GetUserEnteredText());
    if (holds_alternative<LoginError>(login_res)) {
      error_message_ = std::get<LoginError>(login_res).error_message;
      ReloadSubviews();
    } else {
      error_message_ = {};
      ApiWrapper::GetShared() = std::get<ApiWrapper>(login_res);
      AbstractMenuViewController::PresentViewController(destination);
    }
  } else {
    AbstractMenuViewController::PresentViewController(destination);
  }
}

void LoginMenuViewController::TextChanged(TextField &sender,
                                          const std::string &old_text) {}

void LoginMenuViewController::TextEditingFinished(TextField &sender) {}

void LoginMenuViewController::MenuViewWillAppear() {
  AbstractMenuViewController::MenuViewWillAppear();
  ReloadSubviews();
}

void LoginMenuViewController::ReloadSubviews() {
  auto username_label = std::make_shared<Label>(GetMenuView().get(), "Login:");
  auto password_label =
      std::make_shared<Label>(GetMenuView().get(), "Password:");

  username_label->SetDisplayMode(Label::UNDERLINE);
  password_label->SetDisplayMode(Label::UNDERLINE);

  std::vector<std::shared_ptr<AbstractView>> subviews = {
      username_label,
      username_field_,
      password_label,
      password_field_,
      std::make_shared<Label>(GetMenuView().get(), ""), // separator
      login_button_,
  };

  if (error_message_.has_value()) {
    subviews.insert(subviews.begin(), std::make_shared<Label>(GetMenuView().get(), *error_message_));
  }

  GetMenuView()->UpdateSubviews(subviews);
}
