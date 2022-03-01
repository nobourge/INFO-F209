//
// Created by Anton Romanova on 28/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_FRIEND_LIST_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_FRIEND_LIST_VIEW_CONTROLLER_H_

#include "abstract_authed_menu_view_controller.h"

class FriendListViewController: public AbstractAuthedMenuViewController {
public:
  FriendListViewController();

  void ReloadViews();

protected:
  void MenuViewWillAppear() override;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_FRIEND_LIST_VIEW_CONTROLLER_H_
