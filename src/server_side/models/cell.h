//
// Cell.h
// TODO:Description

#include <iostream>
#include "position.h"
#include "wall.h"
#include "common.h"
#include "Pawn.h"
#include <memory>
#include <array>

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_CELL_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_CELL_H_

class Cell {
  // as we are using a walls vector in board we might remove it from there to avoid repetion
  std::array<bool, kNumberOfDirections> walls_; // using a boolean instead of a Wall class should be easier in this case
                                                // because there is no action that might need a wall
  std::shared_ptr<Pawn> pawn_;
  Position pos_;
  bool temp = false;

public:
  Cell();

  bool isPawn() const;
  void setPawn();
  void removePawn();

  bool checkDirection(DIRECTION) const;
  void setWall(DIRECTION);

};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_CELL_H_
