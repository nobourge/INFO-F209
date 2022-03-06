/*
position.cpp
TODO do the description
*/

#include "position.h"

/// overloads == to compare 2 board positions
/// \param pos
/// \return
bool Position::operator==(const Position &pos) const {
  if (this->row == pos.row && this->col == pos.col) {
    return true;
  } else {
    return false;
  }
}

/// substract positions?
/// \param position
/// \return
std::pair<int, int> Position::diff(const Position &position) const {
  return std::pair<int, int> (this->row - position.row, this->col - position.col);
}

///
/// \param low
/// \param high
/// \return
bool Position::IsOutOfBoundaries(const int &low, const int &high) const {
  return (this->col < low || this->col > high - 1 || this->row < low || this->row > high - 1) ? true : false;
}

///
/// \param direction
/// \return
Position Position::operator+(const DIRECTION direction) {
  Position pos;
  switch (direction) {
    case NORTH:
      pos=Position{this->col, this->row-1};
      break;
    case EAST:
      pos=Position{this->col+1, this->row};
      break;
    case SOUTH:
      pos=Position{this->col, this->row+1};
      break;
    case WEST:
      pos=Position{this->col-1, this->row};
      break;
  }
  return pos;
}

///
/// \return
std::unique_ptr<crow::json::wvalue> Position::Serialize() {
  std::unique_ptr<crow::json::wvalue> output = std::make_unique<crow::json::wvalue>();
  (*output)["x"] = col;
  (*output)["y"] = row;
  return output;
}

///
/// \param col
/// \param row
Position::Position(int col, int row) : col(col), row(row) {}
std::optional<Position> Position::FromJson(const crow::json::rvalue &json) {
  Position pos;
  try {
    pos.col = json["x"].i();
    pos.row = json["y"].i();
  } catch (...) {
    return {};
  }

  return pos;
}
