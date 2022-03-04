#include "home_menu_view_controller.h"
#include "new_game_menu_view_controller.h"
#include "friend_list_view_controller.h"
#include "chat_room_view_controller.h"
#include "ranking_view_controller.h"
#include "help_view_controller.h"
#include "join_or_create_game_menu_view_controller.h"
#include "../models/api_wrapper.h"
#include <string>

HomeMenuViewController::HomeMenuViewController()
    : AbstractAuthedMenuViewController(std::make_shared<HomeMenuView>()) {
  auto pMenu = GetMenuView().get();

  logout_button_ = std::make_shared<MenuButtonItem>(pMenu, "Logout", std::optional<std::shared_ptr<AbstractViewController>>{}, pMenu);

  GetMenuView()->UpdateSubviews({
      std::make_shared<MenuButtonItem>(pMenu, "Play", std::make_shared<JoinOrCreateGameMenuViewController>(), pMenu),
      std::make_shared<MenuButtonItem>(pMenu, "Chat", std::make_shared<FriendListViewController>(), pMenu),
      std::make_shared<MenuButtonItem>(pMenu, "Rankings",std::make_shared<RankingMenuViewController>(), pMenu),
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


