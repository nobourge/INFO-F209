#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_RANKING_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_RANKING_VIEW_CONTROLLER_H_

#include "../views/menu_views/ranking_menu_view.h"
#include "abstract_authed_menu_view_controller.h"
#include "../views/menu_views/views/label.h"
#include "../models/user_client.h"

#include <string>


class RankingMenuViewController : public AbstractAuthedMenuViewController {
 public:
  RankingMenuViewController();

protected:
  void MenuViewWillAppear() override;

  void FetchAndUpdate();
  void ReloadSubviews();

  std::shared_ptr<MenuButtonItem> back_btn_ = {};
  std::vector<std::shared_ptr<AbstractView>> leaderboard_views_ = {};
  std::vector<UserClient> users_;
};



#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_MENU_VIEW_CONTROLLER_H_