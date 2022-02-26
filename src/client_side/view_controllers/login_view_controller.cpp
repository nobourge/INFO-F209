#include "login_view_controller.h"


LoginMenuViewController::LoginMenuViewController()
    : MenuViewController(std::make_shared<LoginMenuView>()){}