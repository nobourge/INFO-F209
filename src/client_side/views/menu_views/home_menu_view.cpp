#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "home_menu_view.h"
#include "../../view_controllers/help_view_controller.h"
#include "../../view_controllers/ranking_view_controller.h"

HomeMenuView::HomeMenuView() : AbstractMenuView(menu_name_) {
  UpdateSubviews({
    std::make_shared<MenuButtonItem>(this, "Play", std::optional<std::shared_ptr<AbstractViewController>>{}, this),
    std::make_shared<MenuButtonItem>(this, "Friend List", std::optional<std::shared_ptr<AbstractViewController>>{}, this),
    std::make_shared<MenuButtonItem>(this, "Ranking",std::make_shared<RankingMenuViewController>(), this),
    std::make_shared<MenuButtonItem>(this, "Help", std::make_shared<HelpViewController>(), this),
    std::make_shared<MenuButtonItem>(this, "Quit", std::optional<std::shared_ptr<AbstractViewController>>{}, this),
  });
}
