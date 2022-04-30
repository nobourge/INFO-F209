
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
  Game(const Game &o)
      : game_id_(o.game_id_),
        game_name_(o.game_name_),
        p_board_(std::make_unique<Board>(*o.p_board_)),
        admin_player_(o.admin_player_),
        players_(o.players_),
        current_player_(o.current_player_),
        move_history_(o.move_history_),
        game_on_(o.game_on_),
        ia_player_(o.ia_player_),
        game_mode_(o.game_mode_)
  {}

  Game(const std::vector<std::pair<Position, int>> &playersPair,
       int currentPlayerIndex, std::vector<Position> walls);

  Game(std::string gameName, int nrOfPlayers = 2);

  static Game StartNewGame(std::string gameName, int nrOfPlayers);

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
  const std::unique_ptr<Board> &GetBoard() { return p_board_; }

  crow::json::wvalue GetGameJson();
  static std::optional<Game> InitGameFromJson(const crow::json::rvalue &json);
  [[nodiscard]] const vector<std::shared_ptr<Player>> &GetPlayers() const;
  void SetAdminPlayer(const shared_ptr<Player> &admin_player);

  [[nodiscard]] const vector<std::pair<std::shared_ptr<Player>, std::string>> &
  GetMoveHistory() const;

private:
  std::optional<object_id_t> game_id_;
  std::string game_name_;
  std::unique_ptr<Board> p_board_;
  std::shared_ptr<Player> admin_player_;
  std::vector<std::shared_ptr<Player>> players_;
  std::shared_ptr<Player> current_player_;
  std::vector<std::pair<std::shared_ptr<Player>, std::string>> move_history_ = {};
  bool game_on_;
  bool ia_player_ = false;
  GameMode game_mode_ = Normal;
};

#endif
