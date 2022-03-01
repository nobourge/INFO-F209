#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_LOGIN_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_LOGIN_VIEW_CONTROLLER_H_

#include "../views/menu_views/login_menu_view.h"
#include "abstract_menu_view_controller.h"
#include "ncurses.h"
#include <string>


class LoginMenuViewController : public AbstractMenuViewController, public TextFieldDelegate, public MenuButtonItemDelegate {
 public:
   LoginMenuViewController();

   // MenuButtonItemDelegate
   void PresentController(
       const std::optional<std::shared_ptr<AbstractViewController>>
           &destination,
       MenuButtonItem &sender) override;

   // TextFieldDelegate
   void TextChanged(TextField &sender, const std::string &old_text) override;
   void TextEditingFinished(TextField &sender) override;

 protected:
   void MenuViewWillAppear() override;

 private:
   void ReloadSubviews();

   std::shared_ptr<TextField> username_field_;
   std::shared_ptr<TextField> password_field_;
   std::shared_ptr<MenuButtonItem> login_button_;
   std::optional<std::string> error_message_{};
};



#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_MENU_VIEW_CONTROLLER_H_