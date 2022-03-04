//
// Created by Anton Romanova on 04/03/2022.
//

#include "join_game_menu_view_controller.h"
#include "../views/menu_views/join_game_menu_view.h"

unsigned int JoinGameMenuViewController::GetNumItemsInList() const {
  return game_views_.size();
}

std::shared_ptr<AbstractView>
JoinGameMenuViewController::GetViewAtIndex(unsigned int i) const {
  return game_views_.at(i);
}

void JoinGameMenuViewController::ReloadViews() {
  game_views_ = {};
  for (auto &game_id : games_) {
    game_views_.push_back(std::make_shared<MenuButtonItem>(
        GetMenuView().get(), "Game " + std::to_string(game_id),
        std::optional<std::shared_ptr<AbstractViewController>>(), GetMenuView().get()));
  }
}

JoinGameMenuViewController::JoinGameMenuViewController()
    : AbstractSearchableListMenuViewController(
          std::make_shared<JoinGameMenuView>()) {}

void JoinGameMenuViewController::MenuViewWillAppear() {
  FetchGames();
  ReloadViews();
  AbstractSearchableListMenuViewController::MenuViewWillAppear();
}

bool JoinGameMenuViewController::ShouldDisplayList() const {
  return error_message_.has_value()
             ? false
             : AbstractListMenuViewController::ShouldDisplayList();
}

void JoinGameMenuViewController::FetchGames() {
  auto res = ApiWrapper::GetShared()->GetGamesVector();
  if (holds_alternative<ApiError>(res)) {
    error_message_ = std::get<ApiError>(res).error_message;
    games_ = {};
  } else {
    error_message_ = {};
    games_ = std::get<std::vector<object_id_t>>(res);
  }
}

vector<std::shared_ptr<AbstractView>>
JoinGameMenuViewController::GetHeaderViews() const {
  auto output = AbstractListMenuViewController::GetHeaderViews();
  if (error_message_.has_value()) {
    output.push_back(std::make_shared<Label>(GetMenuView().get(), *error_message_));
  }
  return output;
}
