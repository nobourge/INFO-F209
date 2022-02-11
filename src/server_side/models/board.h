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

class Board: public std::enable_shared_from_this<Board> {
 public:

  std::shared_ptr<Board> Create();
  friend class BoardBuilder;

  std::variant<Cell, Wall> operator [](const Position &) const;

 private:

  Board() = default;

  std::vector<std::vector<Cell>> cells_;
  std::vector<std::vector<Wall>> walls_;
};


#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_
