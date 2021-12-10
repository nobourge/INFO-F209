//
// Created by Anton Romanova on 09/12/2021.
//

#ifndef QUORIDOR_SERVER_SIDE_GAME_LOGIC_BOARD_H_
#define QUORIDOR_SERVER_SIDE_GAME_LOGIC_BOARD_H_

#include "board_position.h"
#include <ostream>
#include <optional>
#include <vector>

class Piece;
class Wall;
class Pawn;

class Board {
 public:
  friend std::ostream &operator<<(std::ostream &os, const Board &board);

  Piece operator[](const BoardPosition &position) const;

  friend class Wall;
  friend class Pawn;

 protected:
  const std::vector<std::vector<std::optional<std::shared_ptr<Wall>>>> &GetWallsGrid() const;
  const std::vector<std::vector<std::optional<std::shared_ptr<Pawn>>>> &GetPawnsGrid() const;

 private:
  // 8x8 and 9x9 grids respectively. This might change in the future if some feature was to be added,
  // so a vector is used instead of an array
  std::vector<std::vector<std::optional<std::shared_ptr<Wall>>>> walls_grid_;
  std::vector<std::vector<std::optional<std::shared_ptr<Pawn>>>> pawns_grid_;
};

#endif //QUORIDOR_SERVER_SIDE_GAME_LOGIC_BOARD_H_
