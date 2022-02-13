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

class Board : public std::enable_shared_from_this<Board> {
 public:

  // std::variant<Cell, Wall> operator [](const Position &) const;
  // if postion is {3, 4} and there is pawn but there is also a wall on the side
  // do we return the pawn or the wall ?
  // also a wall is not placed on top of a Cell but on it's side so I think that
  // return a Cell and dealing with walls elsewhere is easier

  Board(std::vector<Position>, std::vector<Position>);

  bool GetWallBetween(const Cell &, const Cell &) const;
  bool GetWallBetween(const Cell &, const DIRECTION &) const; // might be faster in some cases

  Cell GetCellAtPosition(const Position &) const;

  // replacing the pair by a wall class might be intrestring but as for now
  // it is easier this way

  bool IsWallPossible(const Cell &, const DIRECTION &) const;
  bool IsMovePossible(const Position &, const Position &) const;

  void Movement(const Position &, bool);

  friend std::ostream &operator<<(std::ostream &, const Board &);
  // replacing the overload by a string is easier if we use ncurses

  std::string GetBoardString() const;

  explicit operator std::string() const;;

 private:

  std::vector<Position> pawns_;
  std::array<std::array<Cell, kBoardSize>, kBoardSize> cells_;
  std::array<std::array<bool, kBoardSize * 2 - 1>, kBoardSize * 2 - 1> walls_;  // same problem as in cell.h no need
  // for a class
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_
