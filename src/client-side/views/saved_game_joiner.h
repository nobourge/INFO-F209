//
// Created by Anton Romanova on 11/12/2021.
//

#ifndef QUORIDOR_CLIENT_SIDE_VIEWS_SAVED_GAME_JOINER_H_
#define QUORIDOR_CLIENT_SIDE_VIEWS_SAVED_GAME_JOINER_H_

#include "auto_refreshing_view.h"

class SavedGameJoiner: public AutoRefreshingView {
 private:
  void GetSavedGame();
  void StartGame();
};

#endif //QUORIDOR_CLIENT_SIDE_VIEWS_SAVED_GAME_JOINER_H_
