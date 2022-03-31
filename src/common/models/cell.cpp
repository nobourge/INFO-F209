//
// Cell.h
//

#include "cell.h"

#include <utility>

Cell::Cell() : pawn_{nullptr} { walls_.fill(false); }

///
/// \param direction
void Cell::setWall(DIRECTION direction) { walls_[direction] = true; }

///
/// \param direction
void Cell::unsetWall(DIRECTION direction) { walls_[direction] = false; }

///
/// \param direction
/// \return
bool Cell::checkDirection(DIRECTION direction) const {
  return walls_[direction];
}

/// check if cell contains a pawn or is empty
/// \return
bool Cell::isPawn() const {
  if (pawn_) {
    return true;
  } else {
    return false;
  }
}

///

void Cell::removePawn() {
  pawn_ = nullptr;
}

///
/// \param pawn
void Cell::setPawn(std::shared_ptr<Player> pawn) { pawn_ = std::move(pawn); }

///
/// \return
std::shared_ptr<Player> Cell::getPawn() const { return pawn_; }

///
/// \return
Position Cell::getPos() const { return pos_; }

///
/// \param position
void Cell::setPos(const Position &position) { pos_ = position; }

///
/// \param cell
/// \return
bool Cell::isNeighbour(const Cell &cell) const {
  std::pair<int, int> deltas =
      this->getPos().diff(cell.getPos()); // <deltaRow, deltaCol>
  if (!(-1 <= deltas.first && deltas.first <= 1) ||
      !(-1 <= deltas.second && deltas.second <= 1) ||
      std::abs(deltas.first) == std::abs(deltas.second))
    return false;
  return true;
}

///
/// \param position
/// \return
bool Cell::isNeighbour(const Position &position) const {
  std::pair<int, int> deltas =
      this->getPos().diff(position); // <deltaRow, deltaCol>
  return (!(-1 <= deltas.first && deltas.first <= 1) ||
          !(-1 <= deltas.second && deltas.second <= 1) ||
          std::abs(deltas.first) == std::abs(deltas.second))
             ? false
             : true;
}

crow::json::wvalue Cell::Serialize() {
  crow::json::wvalue output;

  for (int i = 0; i < walls_.size(); i++) {
    output["walls"][i] = walls_.at(i);
  }

  if (pawn_) {
    output["pawn"] = pawn_->Serialize();
  }

  output["position"] = pos_.Serialize();

  return output;
}

optional<Cell>
Cell::FromJson(const crow::json::rvalue &json,
               const unordered_map<string, shared_ptr<Player>> &game_players) {
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

    std::optional<Player> pawn = {};

    if (json.has("pawn")) {
      pawn = Player::FromJson(json["pawn"]);
      if (!pawn.has_value()) { // pawn parsing failed
        return {};
      }
    }

    if (pawn.has_value()) {
      cell.pawn_ = game_players.empty()
                       ? std::make_shared<Player>(*pawn)
                       : game_players.at(uuidToString(pawn->GetUuid()));
    }

  } catch (...) {
    return {};
  }
  return cell;
}
