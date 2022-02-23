#include "ranking_view_controller.h"

RankingMenuViewController::RankingMenuViewController()
    : MenuViewController(std::make_shared<RankingMenuView>()){}