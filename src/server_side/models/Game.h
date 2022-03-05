
#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_Game_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_Game_H_

#include "Player.h"
#include "board.h"
#include "ia.h"
#include "input.h"
#include "memory"
#include "position.h"
#include <optional>



class Game {
public:
  Game();
  Game(std::vector<std::pair<Position, int>> playersPair, int currentPlayerIndex, std::vector<Position> walls);
  Game(std::string gameName, int nrOfPlayers=2);
  ~Game() { delete board; }

  static std::optional<Game> InitFromDB(object_id_t game_id=0);   // initializing the id to make testing easier

  void SaveToDB(std::string game_name, object_id_t game_id=0);

  void SwitchCurrentPlayer();
  void StartTheGame();
  int getScore();
  bool gameOnGoing();
  bool hasCurrentPlayerWon();
  void joinGame();
  void endGame();
  void PlayMove(std::string move);
  // void playCoup();
  void playIaMove();
  void calculateRanking();
  std::shared_ptr<Player> getCurrentPlayer();
  Board *getBoard() { return board; }

  crow::json::wvalue GetGameJson();
  void StartGameFromJson(const crow::json::rvalue &game_json);


private:
  std::string gameName;
  Board *board;
  std::vector<std::shared_ptr<Player>> players;
  std::shared_ptr<Player> currentPlayer;
  bool gameOn;
  bool IaPlayer = false;
  GameMode gameMode = Normal;
};

#endif
