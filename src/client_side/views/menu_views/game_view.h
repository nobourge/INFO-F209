//
// Created by guest on 01/03/2022.
//

#ifndef INFO_F209_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_GAME_VIEW_H_
#define INFO_F209_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_GAME_VIEW_H_
#include "abstract_menu_view.h"

class GameView :public AbstractMenuView{
 public:
  GameView();
protected:
  int GetVerticalGutterSize() const override;
 private:
  constexpr static const char menu_name_[] = "Chat Room Menu";
};

#endif //INFO_F209_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_GAME_VIEW_H_
