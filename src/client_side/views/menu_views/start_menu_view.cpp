#include "start_menu_view.h"
#include "../../view_controllers/view_controller_create_account.h"
#include "../../view_controllers/view_controller_login.h"
#include <vector>

StartMenuView::StartMenuView() : AbstractMenuView(menu_name_) {
  UpdateSubviews({
      std::make_shared<MenuButtonItem>(
          this, "Login", std::make_shared<LoginMenuViewController>(), this),
      std::make_shared<MenuButtonItem>(
          this, "Create an account",
          std::make_shared<CreateAccountViewController>(), this),
  });
}

std::string StartMenuView::GetBackButtonName() const {
  return "Quit";
}
