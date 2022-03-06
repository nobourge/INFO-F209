
#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_Game_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_Game_H_

#include "Player.h"
#include "board.h"
#include "ia.h"
#include "input.h"
#include "memory"
#include "position.h"
#include <optional>

typedef std::string Error;

class Game {
public:
  Game();
  Game(const std::vector<std::pair<Position, int>>& playersPair,
       int currentPlayerIndex, std::vector<Position> walls);

  Game(std::string gameName, int nrOfPlayers = 2);
  ~Game() { delete p_board_; }



  static Game StartNewGame(std::string gameName, int nrOfPlayers);

  static std::optional<Game>
  InitFromDB(object_id_t game_id); // initializing the id to make testing easier

  void SaveToDB(std::string game_name);

  void SwitchCurrentPlayer();
  void StartTheGame();
  int GetScore();
  bool GameOnGoing();
  bool HasCurrentPlayerWon();
  void JoinGame();
  void EndGame();
  std::optional<Error> PlayMove(std::string move);
  void PlayIaMove();
  void CalculateRanking();
  std::shared_ptr<Player> GetCurrentPlayer();
  Board *GetBoard() { return p_board_; }

  crow::json::wvalue GetGameJson();
  static std::optional<Game> InitGameFromJson(const crow::json::rvalue &json);

//  const optional<uint32_t> &GetGameId() const;
//  void SetGameId(const optional<uint32_t> &game_id);
//
//  const string &GetGameName() const;
//  void SetGameName(const string &game_name);

  const vector<std::shared_ptr<Player>> &GetPlayers() const;

private:
  std::optional<object_id_t> game_id_;
  std::string game_name_;
  Board *p_board_;
  std::shared_ptr<Player> admin_player_;
  std::vector<std::shared_ptr<Player>> players_;
  std::shared_ptr<Player> current_player_;
  bool game_on_;
  bool ia_player_ = false;
  GameMode game_mode_ = Normal;
};

#endif
