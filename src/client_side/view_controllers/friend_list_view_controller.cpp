//
// Created by Anton Romanova on 28/02/2022.
//

#include "friend_list_view_controller.h"
#include "../models/api_wrapper.h"
#include "../views/menu_views/friend_list_menu_view.h"
#include "chat_room_view_controller.h"
#include "find_friend_view_controller.h"
#include <algorithm>

FriendListViewController::FriendListViewController()
    : AbstractSearchableListMenuViewController(
          std::make_shared<FriendListMenuView>()) {
  find_new_friends_button_ = std::make_shared<MenuButtonItem>(
      GetMenuView().get(), "Find new friends",
      std::make_shared<FindFriendViewController>(), GetMenuView().get());
}

void FriendListViewController::MenuViewWillAppear() {
  FetchFriends();
  CreateButtonViews();
  AbstractSearchableListMenuViewController::MenuViewWillAppear();
}

void FriendListViewController::FetchFriends() {
  auto user_fetch_attempt =
      ApiWrapper::GetCurrentUserFromSharedApiWrapperInstance();

  if (std::holds_alternative<UserClient>(user_fetch_attempt)) {
    friends_ = std::get<UserClient>(user_fetch_attempt).GetFriends();
    error_message_ = {};
  } else {
    error_message_ = std::get<LoginError>(user_fetch_attempt).error_message;
    friends_ = {};
  }
}
unsigned int FriendListViewController::GetNumItemsInList() const {
  return friends_button_views_.size();
}
std::shared_ptr<AbstractView>
FriendListViewController::GetViewAtIndex(unsigned int i) const {
  return friends_button_views_.at(i);
}

std::vector<std::shared_ptr<AbstractView>>
FriendListViewController::GetHeaderViews() const {
  auto output = AbstractSearchableListMenuViewController::GetHeaderViews();
  if (error_message_.has_value()) {
    output.push_back(std::make_shared<Label>(GetMenuView().get(), *error_message_));
  }
  return output;
}

std::vector<std::shared_ptr<AbstractView>>
FriendListViewController::GetBottomViews() const {
  auto output = AbstractSearchableListMenuViewController::GetBottomViews();
  output.push_back(find_new_friends_button_);
  return output;
}

bool FriendListViewController::ShouldDisplayList() const {
  return !error_message_.has_value();
}

void FriendListViewController::CreateButtonViews() {
  friends_button_views_.clear();
  friends_button_views_.reserve(friends_.size());
  for (auto &user : friends_) {
    friends_button_views_.push_back(std::make_shared<MenuButtonItem>(
        GetMenuView().get(), user.GetUsername().GetValue(),
        std::make_shared<ChatRoomViewController>(user), GetMenuView().get()));
  }
}
void FriendListViewController::MenuViewWillDisappear() {
  AbstractMenuViewController::MenuViewWillDisappear();
  friends_button_views_.clear();
}
