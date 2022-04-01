#include "board_fetcher.h"

BoardFetcher::BoardFetcher(QObject* parent, int game_id) : QThread{parent}, game_id{game_id} {oneMoreTime = false; inGame=true;}

void BoardFetcher::run() {
    while (this->inGame) {
        auto currentUser = ApiWrapper::GetShared()->GetCurrentUser();
        auto game = ApiWrapper::GetShared()->GetGame(static_cast<uint32_t>(game_id));
        if ( !holds_alternative<ApiError>(currentUser) && !holds_alternative<ApiError>(game)) {
            if (get<Game>(game).GetCurrentPlayer()->GetUserId() != get<UserClient>(currentUser).GetId()) {oneMoreTime = true;emit updated();}
        } 
        this->msleep(250);  // arbitrary number
        if (oneMoreTime) {oneMoreTime = false; emit updated();}
    }
}
