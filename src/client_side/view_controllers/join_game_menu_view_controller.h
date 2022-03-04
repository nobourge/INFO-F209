//
// Created by Anton Romanova on 04/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_JOIN_GAME_MENU_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_JOIN_GAME_MENU_VIEW_CONTROLLER_H_

#include "../models/api_wrapper.h"
#include "abstract_searchable_list_menu_view_controller.h"

class JoinGameMenuViewController
    : public AbstractSearchableListMenuViewController {
public:
  JoinGameMenuViewController();

  [[nodiscard]] unsigned int GetNumItemsInList() const override;
  [[nodiscard]] std::shared_ptr<AbstractView> GetViewAtIndex(unsigned int i) const override;
  [[nodiscard]] bool ShouldDisplayList() const override;
  vector<std::shared_ptr<AbstractView>> GetHeaderViews() const override;



protected:
  void FetchGames();
  void ReloadViews();
  std::vector<std::shared_ptr<MenuButtonItem>> game_views_;
  std::vector<object_id_t> games_;
  std::optional<std::string> error_message_;
  void MenuViewWillAppear() override;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_JOIN_GAME_MENU_VIEW_CONTROLLER_H_
