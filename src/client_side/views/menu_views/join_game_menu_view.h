//
// Created by Anton Romanova on 04/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_JOIN_GAME_MENU_VIEW_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_JOIN_GAME_MENU_VIEW_H_

#include "abstract_menu_view.h"
class JoinGameMenuView : public AbstractMenuView {
public:
  JoinGameMenuView();
  static const constexpr char menu_name[] = "Join Game";
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_JOIN_GAME_MENU_VIEW_H_
