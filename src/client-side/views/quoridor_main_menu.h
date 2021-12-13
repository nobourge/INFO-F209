//
// Created by Anton Romanova on 10/12/2021.
//

#ifndef QUORIDOR_CLIENT_SIDE_VIEWS_QUORIDOR_MAIN_MENU_H_
#define QUORIDOR_CLIENT_SIDE_VIEWS_QUORIDOR_MAIN_MENU_H_

#include "auto_refreshing_view.h"

class MainMenuView: AutoRefreshingView {
  void OpenMenu();
  void Display() const;
};

#endif //QUORIDOR_CLIENT_SIDE_VIEWS_QUORIDOR_MAIN_MENU_H_
