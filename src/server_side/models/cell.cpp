//
// Cell.h
//

#include "cell.h"

Cell::Cell(): pawn_{nullptr} {}

void Cell::setWall(DIRECTION direction) {
  walls_[direction] = true;
}

bool Cell::checkDirection(DIRECTION direction) const {
  return walls_[direction];
}

bool Cell::isPawn() const {
  return temp;

  // if (pawn_) {
  //   return true;
  // }else{
  //   return false;
  // }
}

void Cell::removePawn(){
  pawn_ = nullptr;
}

void Cell::setPawn(){
  temp = true; // temp way to test display
  // TODO
}
