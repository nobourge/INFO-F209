//
// Created by Anton Romanova on 09/12/2021.
//

#ifndef QUORIDOR_SERVER_SIDE_GAME_LOGIC_GAME_H_
#define QUORIDOR_SERVER_SIDE_GAME_LOGIC_GAME_H_

#include "board.h"
#include <memory>

class User;

class Game {
 public:
  [[nodiscard]] bool HasGameStarted() const;
  [[nodiscard]] bool IsGameOver() const;

  [[nodiscard]] const std::vector<std::shared_ptr<User>> &GetParticipants() const;

  const Board &GetBoard() const;

 protected:

  void SwitchPlayer();

 private:
  bool          game_started_;
  bool          game_over_;
  Board         board_;

  std::vector<std::shared_ptr<User>> participants_;
};

#endif //QUORIDOR_SERVER_SIDE_GAME_LOGIC_GAME_H_
