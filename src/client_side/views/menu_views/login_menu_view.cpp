#include "login_menu_view.h"
#include "../../view_controllers/home_menu_view_controller.h"
#include "views/text_field.h"
#include <memory>

LoginMenuView::LoginMenuView()
    : AbstractMenuView(menu_name_) {


}

void LoginMenuView::TextChanged(TextField &sender,
                                const std::string &old_text) {}

void LoginMenuView::TextEditingFinished(TextField &sender) {}
