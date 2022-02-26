#include "login_menu_view.h"
#include "../../view_controllers/home_menu_view_controller.h"
#include "views/label.h"
#include "views/text_field.h"
#include <memory>

LoginMenuView::LoginMenuView()
    : AbstractMenuView(menu_name_),
      login_field_(std::make_shared<TextField>(this, "", this)),
      password_field_(std::make_shared<TextField>(this, "", this)) {
  UpdateSubviews({
      std::make_shared<Label>(this, "Login:"),
      login_field_,
      std::make_shared<Label>(this, "Password:"),
      password_field_,
      std::make_shared<Label>(this, ""), // separator
      std::make_shared<MenuButtonItem>(
          this, "Continue", std::make_shared<HomeMenuViewController>(), this),
      std::make_shared<MenuButtonItem>(
          this, "Quit",
          std::optional<std::shared_ptr<AbstractViewController>>{}, this),
  });

  login_field_->SetPlaceholder("empty login");
  password_field_->SetPlaceholder("empty password");

  password_field_->SetDisplayMode(TextField::PASSWORD);

}

void LoginMenuView::TextChanged(TextField &sender,
                                const std::string &old_text) {}

void LoginMenuView::TextEditingFinished(TextField &sender) {}
