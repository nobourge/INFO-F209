#include "board_fetcher.h"

BoardFetcher::BoardFetcher(QObject *parent, int game_id, std::weak_ptr<bool> should_continue_fetching)
    : QThread{parent}, game_id{game_id}, should_continue_fetching_(should_continue_fetching) {
  oneMoreTime = false;
}

void BoardFetcher::run() {
  while (!this->should_continue_fetching_.expired() && *this->should_continue_fetching_.lock()) {
    auto currentUser = ApiWrapper::GetShared()->GetCurrentUser();
    auto game =
        ApiWrapper::GetShared()->GetGame(static_cast<uint32_t>(game_id));
    if (!holds_alternative<ApiError>(currentUser) &&
        !holds_alternative<ApiError>(game)) {
      if (get<Game>(game).GetCurrentPlayer()->GetUserId() !=
          get<UserClient>(currentUser).GetId()) {
        oneMoreTime = true;
        emit updated();
      }
    }
    this->msleep(250); // arbitrary number
    if (oneMoreTime) {
      oneMoreTime = false;
      emit updated();
    }
  }
}
