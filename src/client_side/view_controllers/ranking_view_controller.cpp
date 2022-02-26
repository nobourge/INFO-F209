#include "ranking_view_controller.h"
#include "../models/api_wrapper.h"
#include "../views/menu_views/views/label.h"

RankingMenuViewController::RankingMenuViewController()
    : MenuViewController(std::make_shared<RankingMenuView>()),
      back_btn_(std::make_shared<MenuButtonItem>(
          GetMenuView().get(), "Back",
          std::optional<std::shared_ptr<AbstractViewController>>{}, GetMenuView().get())) {
  GetMenuView()->AddSubview(back_btn_);
}

void RankingMenuViewController::MenuViewWillAppear() {
  MenuViewController::MenuViewWillAppear();
  Update();
}

void RankingMenuViewController::FetchUsers() {
  users_ = ApiWrapper::GetUsersRanked(MAX_NUM_USERS_RANKING_DEFAULT);
}

void RankingMenuViewController::UpdateRankingMenuSubviews() {
  leaderboard_views_ = {};
  leaderboard_views_.reserve(users_->size());
  for (auto &user : *users_) {
    std::string label = user.GetUsername().GetValue();
    label += " : ";
    label += std::to_string(user.GetScore());
    label += " pts";
    leaderboard_views_.push_back(
        std::make_shared<Label>(GetMenuView().get(), label));
  }

  std::vector<std::shared_ptr<AbstractView>> subviews = leaderboard_views_;
  subviews.push_back(back_btn_);
  GetMenuView()->UpdateSubviews(subviews);
}

void RankingMenuViewController::Update() {
  FetchUsers();
  UpdateRankingMenuSubviews();
}
