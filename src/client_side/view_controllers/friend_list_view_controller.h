//
// Created by Anton Romanova on 28/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_FRIEND_LIST_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_FRIEND_LIST_VIEW_CONTROLLER_H_

#include "abstract_authed_menu_view_controller.h"
#include "../views/menu_views/views/text_field.h"
#include "../models/user_client.h"

class FriendListViewController: public AbstractAuthedMenuViewController, public TextFieldDelegate {
public:
  static constexpr const int MAX_NUM_USERS_TO_SHOW = 3;

  FriendListViewController();

  void TextChanged(TextField &sender, const std::string &old_text) override;
  void TextEditingFinished(TextField &sender) override;

  void ReloadViews();

protected:
  void MenuViewWillAppear() override;

private:


  void FetchFriends();
  void FilterFriends();

  std::optional<std::string> error_message_;

  std::vector<UserClient> friends_;
  std::vector<UserClient> friends_to_display;

  std::shared_ptr<TextField> filter_friends_field_;
  std::shared_ptr<MenuButtonItem> find_new_friends_button_;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_FRIEND_LIST_VIEW_CONTROLLER_H_
