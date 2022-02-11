//
// Created by Anton Romanova on 11/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_

#include "cell.h"
#include "wall.h"
#include "position.h"
#include <vector>
#include <variant>
#include <ostream>
#include <optional>

class Board: public std::enable_shared_from_this<Board> {
 public:

  std::shared_ptr<Board> Create(unsigned size_);

//  std::variant<Cell, Wall> operator [](const Position &) const;

  std::optional<Wall> GetWallBetween(const Cell &c1, const Cell &c2) const;

  Cell GetCellAtPosition(const Position &) const;

  friend std::ostream &operator<<(std::ostream &os, const Board &board);

 private:

  Board() = default;

  unsigned size_;

  std::vector<std::vector<Cell>> cells_;
  std::vector<std::vector<Wall>> walls_;
};


#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_
