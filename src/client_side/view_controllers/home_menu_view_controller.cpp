#include <string>
#include "home_menu_view_controller.h"


HomeMenuViewController::HomeMenuViewController()
    : MenuViewController(std::make_shared<HomeMenuView>()) {}