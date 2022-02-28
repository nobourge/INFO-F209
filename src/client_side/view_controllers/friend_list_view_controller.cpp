//
// Created by Anton Romanova on 28/02/2022.
//

#include "friend_list_view_controller.h"
#include "../views/menu_views/friend_list_menu_view.h"
#include "../views/menu_views/views/label.h"
#include "../models/api_wrapper.h"

FriendListViewController::FriendListViewController(): MenuViewController(std::make_shared<FriendListMenuView>()) {
  auto login_res = ApiWrapper::Login("anton", "password");
  std::string label_value = "";
  if (holds_alternative<LoginError>(login_res)) {
    label_value = std::get<LoginError>(login_res).error_message;
  } else {
    label_value = "Welcome, " + get<UserClient>(std::get<ApiWrapper>(login_res).GetCurrentUser()).GetUsername().GetValue();
  }

  GetMenuView()->UpdateSubviews({
      std::make_shared<Label>(GetMenuView().get(), label_value),
      std::make_shared<MenuButtonItem>(GetMenuView().get(), "Back", std::optional<std::shared_ptr<AbstractViewController>>{}, GetMenuView().get()),
  });
}
