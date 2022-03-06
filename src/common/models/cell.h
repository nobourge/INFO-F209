//
// Cell.h
// TODO:Description

#include <iostream>
#include "position.h"
#include "Player.h"
#include <memory>
#include <array>
#include <cmath>

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_CELL_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_CELL_H_

class Cell {
  // as we are using a walls vector in board we might remove it from there to avoid repetition
  std::array<bool, kNumberOfDirections> walls_; // using a boolean instead of a Wall class should be easier in this case
                                                // because there is no action that might need a wall

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

  crow::json::wvalue Serialize() {
    crow::json::wvalue output;

    for (int i = 0; i < walls_.size(); i++) {
      output["walls"][i] = walls_.at(i);
    }

    if (pawn_) {
      output["pawn"] = pawn_->Serialize();
    }

    output["position"] = std::move(*pos_.Serialize());


    return output;
  }

  static std::optional<Cell> FromJson(const crow::json::rvalue &json) {
    Cell cell;

    try {
      for (int i = 0; i < json["walls"].size(); i++) {
        cell.walls_[i] = json["walls"][i].b();
      }
      auto pos = Position::FromJson(json["position"]);
      if (!pos.has_value()) {
        return {};
      }

      cell.pos_ = *pos;

      auto pawn = Player::FromJson(json["pawn"]);

      if (!pawn.has_value()) {
        return {};
      }

      cell.pawn_ = std::make_shared<Player>(*pawn);

    } catch ( ... ) {
      return {};
    }
    return cell;
  }

  bool isNeighbour(const Cell &) const;
  bool isNeighbour(const Position &) const;
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_CELL_H_
