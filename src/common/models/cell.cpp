//
// Cell.h
//

#include "cell.h"

Cell::Cell(): pawn_{nullptr} {
  walls_.fill(false);
}

///
/// \param direction
void Cell::setWall(DIRECTION direction) {
  walls_[direction] = true;
}

///
/// \param direction
void Cell::unsetWall(DIRECTION direction) {
  walls_[direction] = false;
}

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
  }else{
    return false;
  }
}

///

void Cell::removePawn(){
  std::cout<<"removed"<<std::endl;
  pawn_ = nullptr;
}

///
/// \param pawn
void Cell::setPawn(std::shared_ptr<Player> pawn){
  pawn_ = pawn;
}

///
/// \return
std::shared_ptr<Player> Cell::getPawn() const {
  return pawn_;
}

///
/// \return
Position Cell::getPos() const {
  return pos_;
}

///
/// \param position
void Cell::setPos(const Position &position) {
  pos_ = position;
}

///
/// \param cell
/// \return
bool Cell::isNeighbour(const Cell &cell) const {
  std::pair<int, int> deltas = this->getPos().diff(cell.getPos());  // <deltaRow, deltaCol>
  if (!(-1<= deltas.first && deltas.first <= 1) ||
      !(-1<= deltas.second && deltas.second <= 1) ||
      std::abs(deltas.first)==std::abs(deltas.second)) return false;
  return true;
}

///
/// \param position
/// \return
bool Cell::isNeighbour(const Position &position) const {
  std::pair<int, int> deltas = this->getPos().diff(position);  // <deltaRow, deltaCol>
  return (!(-1<= deltas.first && deltas.first <= 1) ||
          !(-1<= deltas.second && deltas.second <= 1) ||
          std::abs(deltas.first)==std::abs(deltas.second)) ? false : true;
}