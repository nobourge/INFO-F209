//
// Cell.h
//

#include "cell.h"

Cell::Cell(): pawn_{nullptr} {
  walls_.fill(false);
}

void Cell::setWall(DIRECTION direction) {
  walls_[direction] = true;
}

bool Cell::checkDirection(DIRECTION direction) const {
  return walls_[direction];
}

bool Cell::isPawn() const {
  if (pawn_) {
    return true;
  }else{
    return false;
  }
}

void Cell::removePawn(){
  pawn_ = nullptr;
}

void Cell::setPawn(){
  pawn_ = std::make_shared<Pawn> ();
}

Position Cell::getPos() const {
  return pos_;
}

bool Cell::isNeighbour(const Cell &cell) const {
  std::pair<int, int> deltas = this->getPos().diff(cell.getPos());  // <deltaRow, deltaCol>
  if (!(-1<= deltas.first <= 1) ||
      !(-1<= deltas.second <= 1) ||
      std::abs(deltas.first)==std::abs(deltas.second)) return false;
  return true;
}
