/*
 board.h
 TODO: Add Description.
*/

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_

#include<iostream>
#include "cell.h"
#include "wall.h"
#include "position.h"
#include <vector>
#include<array>
#include <variant>
#include <memory>
#include <ostream>
#include <optional>


class Board: public std::enable_shared_from_this<Board> {
 public:

  Board();
  std::shared_ptr<Board> Create();

//  std::variant<Cell, Wall> operator [](const Position &) const;

  bool GetWallBetween(const Cell&, const Cell&) const;

  Cell GetCellAtPosition(const Position &) const;

  bool isWallPossible() const;
  bool isMovePossible() const;

  

  friend std::ostream &operator<<(std::ostream &, const Board &);

 private:

  //Board() = default;

  unsigned size_;

  std::vector<std::vector<Cell>> cells_;
  std::vector<std::vector<Wall>> walls_;
  std::shared_ptr<std::array<std::array<Cell,boardSize>,boardSize>> board;


};


#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_
