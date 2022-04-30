//
// Created by Anton Romanova on 04/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_MENU_JOIN_GAME_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_MENU_JOIN_GAME_H_

#include "../models/api_wrapper.h"
#include "view_controller_menu_abstract_searchable_list.h"

class JoinGameMenuViewController
    : public AbstractSearchableListMenuViewController {
public:
  JoinGameMenuViewController();

  [[nodiscard]] unsigned int GetNumItemsInList() const override;
  [[nodiscard]] std::shared_ptr<AbstractView> GetViewAtIndex(unsigned int i) const override;
  [[nodiscard]] bool ShouldDisplayList() const override;
  [[nodiscard]] vector<std::shared_ptr<AbstractView>> GetHeaderViews() const override;

protected:
  void FetchGames();
  void ReloadViews();
  std::vector<std::shared_ptr<MenuButtonItem>> game_views_;
  std::vector<std::tuple<object_id_t, std::string>> games_;
  std::optional<std::string> error_message_;
  void MenuViewWillAppear() override;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_MENU_JOIN_GAME_H_
