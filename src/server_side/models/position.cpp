/*
position.cpp
TODO do the description
*/

#include "position.h"

bool Position::operator==(const Position &pos) const {
  if (this->row == pos.row && this->col == pos.col) {
    return true;
  } else {
    return false;
  }
}

std::pair<int, int> Position::diff(const Position &position) const {
  return std::pair<int, int> (this->row - position.row, this->col - position.col);
}

bool Position::IsOutOfBoundaries(const int &low, const int &high) const {
  return (this->col < low || this->col > high - 1 || this->row < low || this->row > high - 1) ? true : false;
}

Position Position::operator+(const DIRECTION direction) {
  switch (direction) {
    case NORTH:
      return Position{this->col, this->row-1};
      break;
    case EAST:
      return Position{this->col+1, this->row};
      break;
    case SOUTH:
      return Position{this->col, this->row+1};
      break;
    case WEST:
      return Position{this->col-1, this->row};
      break;
  }
}


std::unique_ptr<crow::json::wvalue> Position::Serialize() {
  std::unique_ptr<crow::json::wvalue> output;
  (*output)["x"] = col;
  (*output)["y"] = row;
  return output;
}
