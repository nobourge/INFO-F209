//
// Created by Anton Romanova on 28/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_FRIEND_LIST_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_FRIEND_LIST_H_

#include "view_controller_menu_abstract_searchable_list.h"
#include "../views/menu_views/views/text_field.h"
#include "../../../src/client_side/models/user_client.h"

class FriendListViewController: public AbstractSearchableListMenuViewController {
public:
  FriendListViewController();

  [[nodiscard]] unsigned int GetNumItemsInList() const override;
  [[nodiscard]] std::shared_ptr<AbstractView> GetViewAtIndex(unsigned int i) const override;

  [[nodiscard]] bool ShouldDisplayList() const override;

  [[nodiscard]] std::vector<std::shared_ptr<AbstractView>>
  GetHeaderViews() const override;
  [[nodiscard]] std::vector<std::shared_ptr<AbstractView>>
  GetBottomViews() const override;

protected:
  void MenuViewWillAppear() override;
  void MenuViewWillDisappear() override;

private:


  void FetchFriends();
  void CreateButtonViews();

  std::optional<std::string> error_message_;

  std::vector<UserClient> friends_;
  std::vector<std::shared_ptr<Button>> friends_button_views_;

  std::shared_ptr<MenuButtonItem> find_new_friends_button_;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_FRIEND_LIST_H_
