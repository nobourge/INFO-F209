#include "create_account_view_controller.h"
#include "../views/menu_views/views/label.h"
#include "home_menu_view_controller.h"
#include "../models/api_wrapper.h"

CreateAccountViewController::CreateAccountViewController()
    : AbstractMenuViewController(std::make_shared<CreateAccountMenuView>()) {

  username_field_ = std::make_shared<TextField>(GetMenuView().get(), "", this);
  password_field_ = std::make_shared<TextField>(GetMenuView().get(), "", this);
  confirm_password_field_ =
      std::make_shared<TextField>(GetMenuView().get(), "", this);



  confirm_button_ = std::make_shared<MenuButtonItem>(
      GetMenuView().get(), "Create account",
      std::make_shared<HomeMenuViewController>(), this);



  username_field_->SetPlaceholder("empty login");
  password_field_->SetPlaceholder("empty password");
  confirm_password_field_->SetPlaceholder("empty password");

  password_field_->SetDisplayMode(TextField::PASSWORD);
  confirm_password_field_->SetDisplayMode(TextField::PASSWORD);


  ReloadViews();
}

void CreateAccountViewController::ReloadViews() {
  auto username_label =
      std::make_shared<Label>(GetMenuView().get(), "Username:");
  auto password_label =
      std::make_shared<Label>(GetMenuView().get(), "Password:");
  auto confirm_password_label =
      std::make_shared<Label>(GetMenuView().get(), "Confirm password:");

  username_label->SetDisplayMode(Label::UNDERLINE);
  password_label->SetDisplayMode(Label::UNDERLINE);
  confirm_password_label->SetDisplayMode(Label::UNDERLINE);

  std::vector<std::shared_ptr<AbstractView>> subviews = {
      username_label,
      username_field_,
      password_label,
      password_field_,
      confirm_password_label,
      confirm_password_field_,

      std::make_shared<Label>(GetMenuView().get(), ""), // SEPARATOR

      confirm_button_,
      std::make_shared<MenuButtonItem>(
          GetMenuView().get(), "Quit",
          std::optional<std::shared_ptr<AbstractViewController>>{}, this),
  };

  if (error_message_.has_value()) {
    subviews.insert(subviews.begin(), std::make_shared<Label>(GetMenuView().get(), *error_message_));
  }

  GetMenuView()->UpdateSubviews(subviews);
}

void CreateAccountViewController::TextChanged(TextField &sender,
                                              const std::string &old_text) {}

void CreateAccountViewController::TextEditingFinished(TextField &sender) {}

void CreateAccountViewController::PresentController(
    const std::optional<std::shared_ptr<AbstractViewController>> &destination,
    MenuButtonItem &sender) {

  // we only need
  if (&sender == confirm_button_.get()) {
    auto username = username_field_->GetUserEnteredText();
    auto password = password_field_->GetUserEnteredText();

    if (password != confirm_password_field_->GetUserEnteredText()) {
      error_message_ = "Password mismatch";
    } else {
      // passwords match
      auto api_wrapper = ApiWrapper::CreateAccount(username, password);

      if (holds_alternative<ApiError>(api_wrapper)) {
        // error occurred
        error_message_ = get<ApiError>(api_wrapper).error_message;
      } else {
        // success creating account!
        error_message_ = {};
        AbstractMenuViewController::PresentViewController(destination);
      }
    }


    ReloadViews();

  } else {
    AbstractMenuViewController::PresentViewController(destination);

  }
}

