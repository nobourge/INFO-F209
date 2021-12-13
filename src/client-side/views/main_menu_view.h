//
// Created by Anton Romanova on 11/12/2021.
//

#ifndef QUORIDOR_CLIENT_SIDE_VIEWS_MAIN_MENU_VIEW_H_
#define QUORIDOR_CLIENT_SIDE_VIEWS_MAIN_MENU_VIEW_H_

#include "auto_refreshing_view.h"
#include <string>

class MainMenuView: AutoRefreshingView {
 private:
  InvitationListenenrThread invitation_listener_;
  std::string UserActionChoice();
  void OpenSelectedMenu(std::string selected_menu);
};

#endif //QUORIDOR_CLIENT_SIDE_VIEWS_MAIN_MENU_VIEW_H_
