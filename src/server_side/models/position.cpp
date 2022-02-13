/*
position.cpp
TODO do the description
*/

#include "position.h"

std::pair<int, int> Position::diff(const Position &position) const {
  return std::pair<int, int> (this->col - position.col, this->col - position.col);
}
