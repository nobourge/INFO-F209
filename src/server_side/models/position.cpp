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


std::unique_ptr<crow::json::wvalue> Position::Serialize() {
  std::unique_ptr<crow::json::wvalue> output;
  (*output)["x"] = col;
  (*output)["y"] = row;
  return output;
}
