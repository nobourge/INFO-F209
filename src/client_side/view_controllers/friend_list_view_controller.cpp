//
// Created by Anton Romanova on 28/02/2022.
//

#include "friend_list_view_controller.h"
#include "../models/api_wrapper.h"
#include "../views/menu_views/friend_list_menu_view.h"
#include "../views/menu_views/views/label.h"
#include <algorithm>

FriendListViewController::FriendListViewController()
    : AbstractAuthedMenuViewController(std::make_shared<FriendListMenuView>()) {

  filter_friends_field_ = std::make_shared<TextField>(
      GetMenuView().get(), "", this);

  filter_friends_field_->SetPlaceholder("Filter:");

  find_new_friends_button_ = std::make_shared<MenuButtonItem>(
      GetMenuView().get(), "Find new friends",
      std::optional<std::shared_ptr<AbstractViewController>>(),
      GetMenuView().get());

}

void FriendListViewController::MenuViewWillAppear() {
  AbstractAuthedMenuViewController::MenuViewWillAppear();
  filter_friends_field_->SetInnerText("");
  FetchFriends();
  FilterFriends();
  ReloadViews();
}

void FriendListViewController::ReloadViews() {
  std::vector<std::shared_ptr<AbstractView>> subviews = {};
  std::vector<UserClient> friends = {};


  if (error_message_.has_value()) {
    subviews.push_back(
        std::make_shared<Label>(GetMenuView().get(), *error_message_));
  } else {
    auto num_users_to_show = std::min(MAX_NUM_USERS_TO_SHOW, static_cast<int>(friends_to_display.size()));

    for (int i = 0; i < num_users_to_show; i++) {
      const auto &friend_username = friends_to_display.at(i).GetUsername().GetValue();
      auto view = std::make_shared<Label>(GetMenuView().get(), friend_username);
      subviews.push_back(view);
    }

    if (num_users_to_show < friends_to_display.size()) {
      subviews.push_back(std::make_shared<Label>(GetMenuView().get(), "..."));

      subviews.push_back(std::make_shared<Label>(GetMenuView().get(), "")); // separator
    }

    subviews.push_back(filter_friends_field_);

    subviews.push_back(find_new_friends_button_);

  }


  subviews.push_back(std::make_shared<MenuButtonItem>(
      GetMenuView().get(), "Back",
      std::optional<std::shared_ptr<AbstractViewController>>{},
      GetMenuView().get()));

  GetMenuView()->UpdateSubviews(subviews);
}

void FriendListViewController::TextChanged(TextField &sender,
                                           const std::string &old_text) {
  FilterFriends();
  ReloadViews();
}

void FriendListViewController::TextEditingFinished(TextField &sender) {}

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

void FriendListViewController::FilterFriends() {
  const std::string filter = filter_friends_field_->GetUserEnteredText();

  if (filter.empty()) {
    friends_to_display = friends_;
  } else {
    friends_to_display = {};
    std::copy_if(friends_.begin(), friends_.end(), std::back_inserter(friends_to_display), [&filter] (const UserClient &user) {
      return user.GetUsername().GetValue().find(filter) != std::string::npos;
    });
  }
}
