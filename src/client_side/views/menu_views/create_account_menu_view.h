#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_CREATE_ACCOUNT_MENU_VIEW_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_CREATE_ACCOUNT_MENU_VIEW_H_

#include "abstract_menu_view.h"
#include "views/text_field.h"
#include <cstring>
#include <iostream>
#include <ncurses.h>
#include <vector>

class CreateAccountMenuView : public AbstractMenuView {
public:
  CreateAccountMenuView();

private:
  constexpr static const char menu_name_[] = "Create Account";
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEWS_CREATE_ACCOUNT_MENU_VIEW_H_