#include "home_menu_view_controller.h"
#include "game_mode_selection_menu_view_controller.h"
#include "friend_list_view_controller.h"
#include "chat_room_view_controller.h"
#include "ranking_view_controller.h"
#include "help_view_controller.h"
#include "../models/api_wrapper.h"
#include <string>

HomeMenuViewController::HomeMenuViewController()
    : AbstractAuthedMenuViewController(std::make_shared<HomeMenuView>()) {
  auto pMenu = GetMenuView().get();

  logout_button_ = std::make_shared<MenuButtonItem>(pMenu, "Logout", std::optional<std::shared_ptr<AbstractViewController>>{}, pMenu);

  GetMenuView()->UpdateSubviews({
      std::make_shared<MenuButtonItem>(pMenu, "Play", std::make_shared<GameModeSelectionMenuViewController>(), pMenu),
      std::make_shared<MenuButtonItem>(pMenu, "Friend List", std::make_shared<FriendListViewController>(), pMenu),
      std::make_shared<MenuButtonItem>(pMenu, "Chat Room", std::make_shared<ChatRoomViewController>(), pMenu),
      std::make_shared<MenuButtonItem>(pMenu, "Ranking",std::make_shared<RankingMenuViewController>(), pMenu),
      std::make_shared<MenuButtonItem>(pMenu, "Help", std::make_shared<HelpViewController>(), pMenu),
      logout_button_
  });
}

void HomeMenuViewController::PresentController(
    const std::optional<std::shared_ptr<AbstractViewController>> &destination,
    MenuButtonItem &sender) {
  AbstractMenuViewController::PresentViewController(destination);
  if (&sender == logout_button_.get()) {
    ApiWrapper::GetShared() = {};
  }
}


