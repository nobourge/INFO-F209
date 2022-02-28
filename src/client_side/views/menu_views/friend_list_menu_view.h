//
// Created by Anton Romanova on 28/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_FRIEND_LIST_MENU_VIEW_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_FRIEND_LIST_MENU_VIEW_H_

#include "abstract_menu_view.h"

class FriendListMenuView: public AbstractMenuView {
public:
  FriendListMenuView();
private:
  constexpr static const char menu_name_[] = "My friends";
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_FRIEND_LIST_MENU_VIEW_H_
