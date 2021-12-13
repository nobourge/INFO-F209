//
// Created by Anton Romanova on 09/12/2021.
//

#ifndef QUORIDOR_SERVER_SIDE_GAME_LOGIC_PIECE_H_
#define QUORIDOR_SERVER_SIDE_GAME_LOGIC_PIECE_H_

#include "board.h"
#include "board_position.h"

class Piece {
 public:
  virtual bool Place(const Point &at_pos, const Board &board) = 0;
  virtual ~Piece() = default;
};

class Pawn : public Piece {
 public:
  bool Place(const Point &at_pos, const Board &board) override;
  bool Move(const Point &from_pos, const Point &to_pos, const Board &board);
};

class Wall : public Piece {
 public:
  enum Orientation {
    North, East, South, West;
  };

  void SetOrientation(const Orientation &orientation);

  bool Place(const Point &at_pos, const Board &board) override;
};

#endif //QUORIDOR_SERVER_SIDE_GAME_LOGIC_PIECE_H_
