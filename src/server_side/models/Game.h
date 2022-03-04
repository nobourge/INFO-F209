
#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_Game_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_Game_H_

#include "Player.h"
#include "board.h"
#include "ia.h"
#include "input.h"
#include "memory"
#include "position.h"

class Game {
public:
  Game();
  ~Game() { delete board; }
  void SwitchCurrentPlayer();
  void StartTheGame();
  int getScore();
  bool gameOnGoing();
  bool hasCurrentPlayerWon();
  void joinGame();
  void endGame();
  void playCoup();
  void playIaMove();
  void calculateRanking();
  std::shared_ptr<Player> getCurrentPlayer();
  Board *getBoard() { return board; }

private:
  Board *board;
  std::vector<std::shared_ptr<Player>> players;
  std::shared_ptr<Player> currentPlayer;
  bool gameOn;
  bool IaPlayer = false;
  GameMode gameMode = Normal;
};

#endif
