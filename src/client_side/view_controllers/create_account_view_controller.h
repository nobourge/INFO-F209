#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_CREATE_ACCOUNT_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_CREATE_ACCOUNT_VIEW_CONTROLLER_H_

#include "../views/menu_views/create_account_menu_view.h"
#include "abstract_menu_view_controller.h"
#include "ncurses.h"
#include <string>

class CreateAccountViewController : public AbstractMenuViewController,
                                    public TextFieldDelegate,
                                    public MenuButtonItemDelegate {
public:
  CreateAccountViewController();

  void ReloadViews();

  // TextFieldDelegate
  void TextChanged(TextField &sender, const std::string &old_text) override;
  void TextEditingFinished(TextField &sender) override;

  // MenuButtonItemDelegate
  void PresentController(
      const std::optional<std::shared_ptr<AbstractViewController>> &destination,
      MenuButtonItem &sender) override;

private:

  std::optional<std::string> error_message_ = {};

  std::shared_ptr<TextField> username_field_;
  std::shared_ptr<TextField> password_field_;
  std::shared_ptr<TextField> confirm_password_field_;

  std::shared_ptr<MenuButtonItem> confirm_button_;

};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_CREATE_ACCOUNT_VIEW_CONTROLLER_H_