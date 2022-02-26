#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_RANKING_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_RANKING_VIEW_CONTROLLER_H_

#include "../views/menu_views/ranking_menu_view.h"
#include "menu_view_controller.h"
#include "../../common/models/user/user.h"
#include "../views/menu_views/views/label.h"

#include <string>


class RankingMenuViewController : public MenuViewController {
 public:
  RankingMenuViewController();

protected:

  void Update();
  void FetchUsers();
  void UpdateRankingMenuSubviews();

  std::shared_ptr<MenuButtonItem> back_btn_;
  std::vector<std::shared_ptr<AbstractView>> leaderboard_views_;
  std::unique_ptr<std::vector<User>> users_;
  void MenuViewWillAppear() override;
};



#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_MENU_VIEW_CONTROLLER_H_