//
// Created by Anton Romanova on 04/03/2022.
//

#include "view_controller_menu_join_game.h"
#include "../views/menu_views/join_game_menu_view.h"
#include "view_controller_game.h"

unsigned int JoinGameMenuViewController::GetNumItemsInList() const {
  return game_views_.size();
}

std::shared_ptr<AbstractView>
JoinGameMenuViewController::GetViewAtIndex(unsigned int i) const {
  return game_views_.at(i);
}

void JoinGameMenuViewController::ReloadViews() {
  game_views_ = {};
  for (auto & game : games_) {
    game_views_.push_back(std::make_shared<MenuButtonItem>(
        GetMenuView().get(), get<1>(game),
        std::make_shared<GameViewController>(get<0>(game)), GetMenuView().get()));
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
  auto res = ApiWrapper::GetShared()->GetGameRoomNames();
  if (holds_alternative<ApiError>(res)) {
    error_message_ = std::get<ApiError>(res).error_message;
    games_ = {};
  } else {
    error_message_ = {};
    games_ = std::move(std::get<std::vector<std::tuple<object_id_t, std::string>>>(res));
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
