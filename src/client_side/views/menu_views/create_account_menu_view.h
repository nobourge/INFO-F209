#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_CREATE_ACCOUNT_MENU_VIEW_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_CREATE_ACCOUNT_MENU_VIEW_H_

#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "abstract_menu_view.h"
#include "views/text_field.h"

class CreateAccountMenuView : public AbstractMenuView {
 public:
  CreateAccountMenuView();
 private:
  constexpr static const char menu_name_[] = "Create Account";
};

#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEWS_CREATE_ACCOUNT_MENU_VIEW_H_