/*
 board.h
 TODO: Add Description.
*/

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_

#include <iostream>
#include "cell.h"
#include "wall.h"
#include "position.h"
#include <vector>
#include <variant>
#include <memory>
#include <ostream>
#include <optional>
#include <string>


class Board: public std::enable_shared_from_this<Board> {
public:

  std::shared_ptr<Board> Create();

  // std::variant<Cell, Wall> operator [](const Position &) const;
  // if postion is {3, 4} and there is pawn but there is also a wall on the side
  // do we return the pawn or the wall ?
  // also a wall is not placed on top of a Cell but on it's side so I think that
  // return a Cell and dealing with walls elsewhere is easier

  Board(std::vector<Position>, std::vector<Position>);

  

  bool GetWallBetween(const Cell&, const Cell&) const;

  Cell GetCellAtPosition(const Position &) const;

  bool isWallPossible(Position) const;
  bool isMovePossible(Position, Position) const;

  void Movement(Position,bool);

  friend std::ostream &operator<<(std::ostream &, const Board &);
  // replacing the overlaod by a string is easier if we use ncurses

  std::string getBoardString() const;

private:

  Board() = default;

  unsigned size_;

  std::array<std::array<Cell, kBoardSize>, kBoardSize> cells_;
  // std::vector<std::vector<Wall>> walls_;
  std::array<std::array<bool, kBoardSize*2>, kBoardSize*2> walls_;  // same problem as in cell.h no need
                                                                    // for a class
};


#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_