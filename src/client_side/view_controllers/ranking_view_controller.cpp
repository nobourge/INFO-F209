#include "ranking_view_controller.h"
#include "../models/api_wrapper.h"
#include "../views/menu_views/views/label.h"

RankingMenuViewController::RankingMenuViewController()
    : AbstractAuthedMenuViewController(std::make_shared<RankingMenuView>()), users_(),
      back_btn_(std::make_shared<MenuButtonItem>(
          GetMenuView().get(), "Back",
          std::optional<std::shared_ptr<AbstractViewController>>{},
          GetMenuView().get())) {
  GetMenuView()->AddSubview(back_btn_);
}

void RankingMenuViewController::MenuViewWillAppear() {
  AbstractMenuViewController::MenuViewWillAppear();
  FetchAndUpdate();
}

void RankingMenuViewController::FetchAndUpdate() {
  try {
    users_ = ApiWrapper::GetUsersRanked(MAX_NUM_USERS_RANKING_DEFAULT);
  } catch (const std::runtime_error &) {
    users_.clear();
  }

  ReloadSubviews();
}

void RankingMenuViewController::ReloadSubviews() {
  leaderboard_views_ = {};
  if (!users_.empty()) {
    leaderboard_views_.reserve(users_.size());
    for (auto &user : users_) {
      std::string label = user.GetUsername().GetValue();
      label += " : ";
      label += std::to_string(user.GetScore());
      label += " pts";
      leaderboard_views_.push_back(
          std::make_shared<Label>(GetMenuView().get(), label));
    }
  } else {
    leaderboard_views_ = {
        std::make_shared<Label>(GetMenuView().get(), "Could not fetch..."),
        std::make_shared<Label>(
            GetMenuView().get(),
            "Double check whether the server is running or not")};
  }

  std::vector<std::shared_ptr<AbstractView>> subviews = leaderboard_views_;
  subviews.push_back(back_btn_);
  GetMenuView()->UpdateSubviews(subviews);
}
