//
// Created by Anton Romanova on 01/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_FIND_FRIEND_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_FIND_FRIEND_H_

#include "view_controller_menu_abstract.h"
#include "../models/user_client.h"
#include "../views/menu_views/views/text_field.h"
#include "view_controller_menu_abstract_searchable_list.h"

class FindFriendViewController : public AbstractSearchableListMenuViewController {
public:
  FindFriendViewController();

  [[nodiscard]] unsigned int GetNumItemsInList() const override;
  [[nodiscard]] std::shared_ptr<AbstractView> GetViewAtIndex(unsigned int i) const override;

protected:
  void MenuViewWillAppear() override;

public:
  [[nodiscard]] std::vector<std::shared_ptr<AbstractView>> GetHeaderViews() const override;
  [[nodiscard]] bool ShouldDisplayList() const override;

private:

  void CreateViewsForUsers();

  void FetchUsers();
  void FetchUsersExceptCurrentUser();


  void AddFriend(const UserClient &user);

  std::vector<UserClient> users_;
  std::vector<std::shared_ptr<Button>> add_user_as_friend_buttons;


  std::optional<std::string> username_of_last_added_friend_;
  std::optional<std::string> error_message_;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_FIND_FRIEND_H_
