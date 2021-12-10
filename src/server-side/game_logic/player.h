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
  bool CanMovePawn(const BoardPosition &to_pos);
  bool CanPlaceWall(const BoardPosition &to_pos)

  // these throw exceptions if an error occurs if the move is invalid
  void MovePawn(const BoardPosition &to_pos);
  void PlaceWall(const BoardPosition &to_pos);

 private:
  unsigned              available_walls_;

  std::weak_ptr<Game>   game_;
  std::shared_ptr<Pawn> pawn_;

  std::vector<std::shared_ptr<Wall>> walls_;
};

#endif //QUORIDOR_SERVER_SIDE_GAME_LOGIC_PLAYER_H_
