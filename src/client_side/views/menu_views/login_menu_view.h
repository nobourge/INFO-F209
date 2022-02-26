#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_LOGIN_MENU_VIEW_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_LOGIN_MENU_VIEW_H_

#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "abstract_menu_view.h"
#include "views/text_field.h"

class LoginMenuView : public AbstractMenuView, public TextFieldDelegate {
 public:
  void TextChanged(TextField &sender, const std::string &old_text) override;
  void TextEditingFinished(TextField &sender) override;
  LoginMenuView();
 private:
   std::shared_ptr<TextField> text_field_;
  constexpr static const char menu_name_[] = "Help Menu";
};

#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEWS_LOGIN_MENU_VIEW_H_