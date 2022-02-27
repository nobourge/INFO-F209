#include "create_account_view_controller.h"


CreateAccountViewController::CreateAccountViewController()
    : MenuViewController(std::make_shared<CreateAccountMenuView>()){}