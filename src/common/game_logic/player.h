//
// Created by Anton Romanova on 09/12/2021.
//

#ifndef QUORIDOR_SERVER_SIDE_GAME_LOGIC_PLAYER_H_
#define QUORIDOR_SERVER_SIDE_GAME_LOGIC_PLAYER_H_

#include "board_position.h"
#include "piece.h"
#include "game.h"
#include <memory>

class Player {
 public:
  bool CanMovePawn(const Point &to_pos);
  bool CanPlaceWall(const Point &to_pos);

  // these throw exceptions if an error occurs if the move is invalid
  void MovePawn(const Point &to_pos);
  void PlaceWall(const Point &to_pos);

 private:
  std::weak_ptr<User> controlling_user_;

  unsigned              available_walls_;

  std::weak_ptr<Game>   game_;
  std::shared_ptr<Pawn> pawn_;

  std::vector<std::shared_ptr<Wall>> walls_;
};

#endif //QUORIDOR_SERVER_SIDE_GAME_LOGIC_PLAYER_H_
