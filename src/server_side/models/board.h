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

  Cell GetCellAtPosition(const Position &) const;

  bool IsWallPossible(const Position &) const;
  bool IsMovePossible(const Position &start, const Position &end) const;

  void Movement(const Position &, bool);

  friend std::ostream &operator<<(std::ostream &, const Board &);
  // replacing the overlaod by a string is easier if we use ncurses

  std::string GetBoardString() const;

  explicit operator std::string() const;;

 private:

  std::array<std::array<Cell, kBoardSize>, kBoardSize> cells_;
  std::array<std::array<bool, kBoardSize * 2>, kBoardSize * 2> walls_;  // same problem as in cell.h no need
  // for a class
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_