//
// Created by Anton Romanova on 01/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_FIND_FRIEND_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_FIND_FRIEND_VIEW_CONTROLLER_H_

#include "abstract_menu_view_controller.h"
#include "../models/user_client.h"
#include "../views/menu_views/views/text_field.h"
#include "abstract_searchable_list_menu_view_controller.h"

class FindFriendViewController : public AbstractSearchableListMenuViewController {
public:
  FindFriendViewController();

  [[nodiscard]] unsigned int GetNumViewsToSearch() const override;
  [[nodiscard]] std::shared_ptr<AbstractView> GetViewAtIndex(unsigned int i) const override;

protected:
  void MenuViewWillAppear() override;

public:
  std::optional<std::shared_ptr<AbstractView>> GetHeaderView() const override;
  bool DisplayList() const override;

private:

  void CreateViewsForUsers();

  void FetchUsers();


  void AddFriend(const UserClient &user);

  std::vector<UserClient> users_;
  std::vector<std::shared_ptr<Button>> add_user_as_friend_buttons;


  std::optional<std::string> username_of_last_added_friend_;
  std::optional<std::string> error_message_;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_FIND_FRIEND_VIEW_CONTROLLER_H_
