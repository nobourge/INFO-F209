#include <vector>
#include "start_menu_view.h"
#include "../../view_controllers/create_account_view_controller.h"
#include "../../view_controllers/login_view_controller.h"

StartMenuView::StartMenuView() : AbstractMenuView(menu_name_) {
  UpdateSubviews({
    std::make_shared<MenuButtonItem>(this, "Login", std::make_shared<LoginMenuViewController>(), this),
    std::make_shared<MenuButtonItem>(this, "Create an account", std::make_shared<CreateAccountViewController>(), this),
    std::make_shared<MenuButtonItem>(this, "Quit", std::optional<std::shared_ptr<AbstractViewController>>{}, this)});

}