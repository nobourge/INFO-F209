//
// Created by Anton Romanova on 23/02/2022.
//

#include "view_controller_help.h"
#include "../views/menu_views/help_menu_view.h"

HelpViewController::HelpViewController() : AbstractAuthedMenuViewController(std::make_shared<HelpMenuView>()) {

}
