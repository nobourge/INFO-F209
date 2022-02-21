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

void Cell::unsetWall(DIRECTION direction) {
  walls_[direction] = false;
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
  std::cout<<"removed"<<std::endl;
  pawn_ = nullptr;
}

void Cell::setPawn(std::shared_ptr<Player> pawn){
  pawn_ = pawn;
}

std::shared_ptr<Player> Cell::getPawn() const {
  return pawn_;
}

Position Cell::getPos() const {
  return pos_;
}

void Cell::setPos(const Position &position) {
  pos_ = position;
}

bool Cell::isNeighbour(const Cell &cell) const {
  std::pair<int, int> deltas = this->getPos().diff(cell.getPos());  // <deltaRow, deltaCol>
  if (!(-1<= deltas.first && deltas.first  <= 1) ||
      !(-1<= deltas.second && deltas.second <= 1) ||
      std::abs(deltas.first)==std::abs(deltas.second)) return false;
  return true;
}

bool Cell::isNeighbour(const Position &position) const {
  std::pair<int, int> deltas = this->getPos().diff(position);  // <deltaRow, deltaCol>
  return (!(-1<= deltas.first <= 1) ||
          !(-1<= deltas.second <= 1) ||
          std::abs(deltas.first)==std::abs(deltas.second)) ? false : true;
}
