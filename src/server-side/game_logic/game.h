//
// Created by Anton Romanova on 09/12/2021.
//

#ifndef INFO_F209_HEADERS_SERVER_SIDE_GAME_H_
#define INFO_F209_HEADERS_SERVER_SIDE_GAME_H_

#include "board.h"
#include "../platform/user.h"
#include <memory>

class User;

class Game {
  [[nodiscard]] bool HasGameStarted() const;
  [[nodiscard]] bool IsGameOver() const;

  [[nodiscard]] const std::vector<std::shared_ptr<User>> &GetParticipants() const;

  bool IsActionValid()


 protected:

  void SwitchPlayer();

 private:
  bool          game_started_;
  bool          game_over_;
  Board         board_;

  std::vector<std::shared_ptr<User>> participants_;
};

#endif //INFO_F209_HEADERS_SERVER_SIDE_GAME_H_
