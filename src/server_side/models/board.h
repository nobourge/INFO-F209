/*
 board.h
 TODO: Add Description.
*/

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_

#include <iostream>
#include "cell.h"
#include "position.h"
#include <vector>
#include <variant>
#include <memory>
#include <ostream>
#include <optional>
#include <string>
#include <random>
#include <algorithm>
#include "database.h"
#include "database.h"

class Board : public std::enable_shared_from_this<Board>{
 public:

  // std::variant<Cell, Wall> operator [](const Position &) const;
  // if position is {3, 4} and there is pawn but there is also a wall on the side
  // do we return the pawn or the wall ?
  // also, a wall is not placed on top of a Cell but on it's side, so I think that
  // return a Cell and dealing with walls elsewhere is easier

  Board(std::vector<std::shared_ptr<Player>>, std::vector<Position>);
  Board(std::string);

  // should be implementing DatabaseCompatible
  void SaveToDB() const;
  std::string GetSerializedString() const;
  std::string GetPositionSerialization(const Position) const;
  std::string GetWallsSerialization() const;
  std::vector<Position> GetWallFromWallSerialization(std::string); // the use of position here only
                                                        // provides an easier way to store
                                                        // pair than using pair<int, int>
                                                        // it's not a real position
  Position GetPositionFromPositionSerialization(std::string);

  bool GetWallBetween(const Cell &, const Cell &) const;
  bool GetWallBetween(const Cell &, const DIRECTION &) const; // might be faster in some cases

  Cell GetCellAtPosition(const Position &) const;

  // replacing the pair by a wall class might be interesting but as for now
  // it is easier this way

  bool HasReachedEnd(const Position, const DIRECTION) const;
  bool HasPathToEnd(std::vector<Position>, const DIRECTION);

  bool IsWallPossible(const Position, const Position, const DIRECTION );
  bool IsMovePossible(const Position &, const Position &) const;

  std::vector<DIRECTION> PossiblePawnHops(const Position, const DIRECTION );
  void Movement(const Position, const Position);
  void PlaceWall(Position,Position,DIRECTION);

  friend std::ostream &operator<<(std::ostream &, const Board &);
  // replacing the overload by a string is easier if we use ncurses

  std::string GetBoardString() const;

  void randomWallPlacement();
  DIRECTION getOpposite(DIRECTION);
  Position getOppositeCell(Position,DIRECTION);

  explicit operator std::string() const;


 private:

  std::vector<std::shared_ptr<Player>> pawns_;
  std::array<std::array<Cell, kBoardSize>, kBoardSize> cells_;
  std::array<std::array<bool, kBoardSize * 2 - 1>, kBoardSize * 2 - 1> walls_;  // same problem as in cell.h no need
  // for a class
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_
