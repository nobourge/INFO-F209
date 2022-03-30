//
// Cell.h
// TODO:Description

#include "../utils.h"
#include "Player.h"
#include "position.h"
#include <array>
#include <cmath>
#include <iostream>
#include <memory>

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_CELL_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_CELL_H_

class Cell {
  // as we are using a walls vector in board we might remove it from there to
  // avoid repetition
  std::array<bool, kNumberOfDirections>
      walls_; // using a boolean instead of a Wall class should be easier in
              // this case because there is no action that might need a wall

  std::shared_ptr<Player> pawn_;
  Position pos_;

public:
  Cell();

  bool isPawn() const;
  void setPawn(std::shared_ptr<Player>);
  std::shared_ptr<Player> getPawn() const;
  void removePawn();

  bool checkDirection(DIRECTION) const;
  void setWall(DIRECTION);
  void unsetWall(DIRECTION);

  Position getPos() const;
  void setPos(const Position &);

  crow::json::wvalue Serialize();

  static optional<Cell>
  FromJson(const crow::json::rvalue &json,
           const unordered_map<string, shared_ptr<Player>> &game_players);

  bool isNeighbour(const Cell &) const;
  bool isNeighbour(const Position &) const;
};

#endif // QUORIDOR_SRC_SERVER_SIDE_MODELS_CELL_H_
