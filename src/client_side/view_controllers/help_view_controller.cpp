//
// Created by Anton Romanova on 23/02/2022.
//

#include "help_view_controller.h"
#include "../views/menu_views/help_menu_view.h"

HelpViewController::HelpViewController() : AbstractAuthedMenuViewController(std::make_shared<HelpMenuView>()) {

}
