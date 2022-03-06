
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
  Game(std::string gameName, object_id_t game_id, int nrOfPlayers=2);
  ~Game() { delete board; }

  static Game StartNewGame(std::string gameName, int nrOfPlayers, object_id_t board_id=0);   // initializing the id to make testing easier
  static std::optional<Game> InitFromDB(object_id_t game_id=0);   // initializing the id to make testing easier

  void SaveToDB(std::string game_name);

  void SwitchCurrentPlayer();
  void StartTheGame();
  int getScore();
  bool gameOnGoing();
  bool hasCurrentPlayerWon();
  void joinGame();
  void endGame();
  void PlayMove(std::string move);
  void playIaMove();
  void calculateRanking();
  std::shared_ptr<Player> getCurrentPlayer();
  Board *getBoard() { return board; }

  crow::json::wvalue GetGameJson();
  static std::optional<Game> StartGameFromJson(const crow::json::rvalue &json);


private:
  std::string gameName;
  Board *board;
  std::shared_ptr<Player> admin_player;
  std::vector<std::shared_ptr<Player>> players;
  std::shared_ptr<Player> currentPlayer;
  bool gameOn;
  bool IaPlayer = false;
  GameMode gameMode = Normal;
};

#endif
