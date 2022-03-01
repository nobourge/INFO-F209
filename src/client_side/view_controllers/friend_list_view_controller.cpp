//
// Created by Anton Romanova on 28/02/2022.
//

#include "friend_list_view_controller.h"
#include "../models/api_wrapper.h"
#include "../views/menu_views/friend_list_menu_view.h"
#include "../views/menu_views/views/label.h"

FriendListViewController::FriendListViewController()
    : AbstractAuthedMenuViewController(std::make_shared<FriendListMenuView>()) {
  ReloadViews();
}

void FriendListViewController::MenuViewWillAppear() {
  AbstractAuthedMenuViewController::MenuViewWillAppear();
  ReloadViews();
}

void FriendListViewController::ReloadViews() {
  std::vector<std::shared_ptr<AbstractView>> subviews = {};
  std::optional<std::string> error_message = {};

  if (ApiWrapper::GetShared().has_value()) {
    auto optional_user = ApiWrapper::GetShared()->GetCurrentUser();
    if (holds_alternative<UserClient>(optional_user)) {
      UserClient &user = std::get<UserClient>(optional_user);

      for (const auto &friend_ : user.GetFriends()) {
        subviews.push_back(std::make_shared<Label>(
            GetMenuView().get(), friend_.GetUsername().GetValue()));
      }

    } else {
      error_message = "User is not signed in: " +
                      std::get<LoginError>(optional_user).error_message;
    }
  } else {
    error_message = "Sign in first";
  }

  if (error_message.has_value()) {
    subviews.push_back(
        std::make_shared<Label>(GetMenuView().get(), *error_message));
  } else {
  }

  subviews.push_back(std::make_shared<MenuButtonItem>(
      GetMenuView().get(), "Back",
      std::optional<std::shared_ptr<AbstractViewController>>{},
      GetMenuView().get()));

  GetMenuView()->UpdateSubviews(subviews);
}
