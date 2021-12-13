//
// Created by Anton Romanova on 11/12/2021.
//

#ifndef QUORIDOR_CLIENT_SIDE_VIEWS_GAME_CONFIGURATOR_MENU_VIEW_H_
#define QUORIDOR_CLIENT_SIDE_VIEWS_GAME_CONFIGURATOR_MENU_VIEW_H_

#include <string>

class GameConfiguratorMenuView {
 private:
  int selectedBoardSize();
  User invitedPlayer();
  std::string selectedGameMode();
  int selectedNumberOfPlayers();
  void startedGame(int user_id, int opponent_id, int boardSize, std::string game_mode);
  void startedGame(std::vector<User> opponents,
                   int boardSize,
                   string game_mode);
};

#endif //QUORIDOR_CLIENT_SIDE_VIEWS_GAME_CONFIGURATOR_MENU_VIEW_H_
