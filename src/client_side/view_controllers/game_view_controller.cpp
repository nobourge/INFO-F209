//
// Created by guest on 01/03/2022.
//

#include "game_view_controller.h"
#include "../views/menu_views/game_view.h"
#include "../views/menu_views/help_menu_view.h"

GameViewController::GameViewController(object_id_t game_id)
    : AbstractAuthedMenuViewController(std::make_shared<GameView>()),
      game_id_(game_id) {

  move_field_ = std::make_shared<TextField>(GetMenuView().get(), "", this);
  move_field_->SetPlaceholder("Move:");
}

void GameViewController::TextChanged(TextField &sender,
                                     const std::string &old_text) {}

void GameViewController::TextEditingFinished(TextField &sender) {
  if (&sender == move_field_.get()) {

    auto move_res = ApiWrapper::GetShared()->PerformGameMove(
        game_id_, sender.GetUserEnteredText());

    if (move_res.has_value()) {
      non_disruptive_error_message_ = (*move_res).error_message;
    } else {
      sender.SetInnerText("");
      FetchBoardReprAndUpdateSubviews();
    }
  }
}

void GameViewController::MenuViewWillAppear() {
  FetchBoardReprAndUpdateSubviews();
  UpdateSubviews();
  AbstractAuthedMenuViewController::MenuViewWillAppear();
}

void GameViewController::UpdateSubviews() {
  std::vector<std::shared_ptr<AbstractView>> subviews_;

  Label separator_view = {GetMenuView().get(), ""};

  if (error_message_.has_value()) {
    subviews_.push_back(
        std::make_shared<Label>(GetMenuView().get(), *error_message_));
    subviews_.push_back(std::make_shared<Label>(separator_view));
  } else {
    if (non_disruptive_error_message_.has_value()) {
      subviews_.push_back(std::make_shared<Label>(GetMenuView().get(), *non_disruptive_error_message_));
      subviews_.push_back(std::make_shared<Label>(separator_view));
    }
    subviews_.push_back(move_field_);
    subviews_.push_back(std::make_shared<Label>(separator_view));

    for (std::string &line : board_repr_lines_) {
      subviews_.push_back(std::make_shared<Label>(GetMenuView().get(), line));
    }

    subviews_.push_back(std::make_shared<Label>(separator_view));
  }

  GetMenuView()->UpdateSubviews(subviews_);
}

void GameViewController::FetchBoardReprAndUpdateSubviews() {
  auto optional_game = ApiWrapper::GetShared()->GetGameReprWithGameId(game_id_);

  error_message_ = {};
  board_repr_lines_ = {};
  non_disruptive_error_message_ = {};

  if (holds_alternative<std::string>(optional_game)) {

    error_message_ = {};

    // this basically splits the board into substrings separated by "\n"
    // (lines)
    std::stringstream board_string_stream(std::get<std::string>(optional_game));
    std::string current_item = {};

    while (std::getline(board_string_stream, current_item)) {
      board_repr_lines_.push_back(current_item);
    }

  } else {
    error_message_ = std::get<ApiError>(optional_game).error_message;
  }

  last_fetched_board_ = GET_TIME_IN_MILLIS;
  UpdateSubviews();
}

void GameViewController::Draw(WINDOW *window) {
  if (ShouldFetchBoard()) {
    FetchBoardReprAndUpdateSubviews();
  }
  AbstractMenuViewController::Draw(window);
}
