//
// Created by Anton Romanova on 01/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_FIND_NEW_FRIEND_MENU_VIEW_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_FIND_NEW_FRIEND_MENU_VIEW_H_

#include "abstract_menu_view.h"

class FindNewFriendMenuView : public AbstractMenuView {
public:
  FindNewFriendMenuView();
  static constexpr char menu_name_[] = "Find new friend";
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_FIND_NEW_FRIEND_MENU_VIEW_H_
