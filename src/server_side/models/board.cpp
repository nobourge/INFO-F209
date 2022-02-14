/*
board.cpp
TODO do the description
*/
#include "board.h"
#include <iostream>

using namespace std;

Board::Board(std::vector<Position> pawnsPosition, std::vector<Position> wallsPosition) {
  // setting up the board by trusting the positions to be possible

  // for (int row = 0; row < kBoardSize * 2; row++) { // initializing the two arrays
  //   for (int col = 0; col < kBoardSize * 2; col++) {
  //     if (row < kBoardSize && col < kBoardSize) cells_[row][col] = Cell{};
  //     walls_[row][col] = false;
  //   }
  // }


  for (Position pos : pawnsPosition) {
    cells_[pos.row][pos.col].setPawn();
    pawns_.push_back(pos);
  }

  for (Position pos : wallsPosition) {
    walls_[pos.row][pos.col] = true;
    if (pos.row % 2 != 0) {
      cells_[pos.row/2][pos.col/2].setWall(SOUTH);
      cells_[pos.row/2+1][pos.col/2].setWall(NORTH);
    } else {
      cells_[pos.row/2][pos.col/2].setWall(EAST);
      cells_[pos.row/2][pos.col/2 + 1].setWall(WEST);
    }
  }
}

std::string Board::GetBoardString() const {
  std::string boardString;
  for (int row = 0; row < kBoardSize * 2 - 1; row++) {
    for (int col = 0; col < kBoardSize * 2 - 1; col++) {
      if (row % 2 == 0 && col % 2 == 0) {  // printing the cells
        if (col == 0) {
          boardString += kAlphabet[row / 2];
          boardString += " ";
        }
        if (cells_[row / 2][col / 2].isPawn()) {
          boardString += " p "; // player
        } else {
          boardString += "   "; // blank
        }
      }

      if (col == 0 && row % 2 != 0) { // cell space
        boardString += "  "; // adding space to align with alphabet
      }
      if (walls_[row][col]) {
        if (col % 2 != 0) {
          boardString += "┃"; // wall
        } else {
          boardString += "━━━"; // wall
        }
      } else {
        if (row % 2 != 0) {
          if (col % 2 == 0) {
            boardString += "┄┄┄";  //using pretty dash lines for the print unsure
            //about portability
          } else {
            boardString += "┆";
          }
        } else if (col % 2 != 0) {
          boardString += "┆";
        }
      }
    }
    boardString += '\n';
  }

  // adding the numbers on the bottom row
  boardString += "   ";
  for (int row = 0; row < 9; row++) {
    boardString += std::to_string(row);
    boardString += "   ";
  }

  return boardString;

}

bool Board::GetWallBetween(const Cell &firstCell, const Cell &secondCell) const {
  if (! firstCell.isNeighbour(secondCell)) return false;
  std::pair<int, int> deltas = firstCell.getPos().diff(secondCell.getPos());  // first is col
  if (deltas.first != 0) {
    if (deltas.first > 0) return firstCell.checkDirection(WEST);
    return firstCell.checkDirection(EAST);
  } else {
    if (deltas.second > 0) return firstCell.checkDirection(NORTH);
    return firstCell.checkDirection(SOUTH);
  }
}

bool Board::GetWallBetween(const Cell &cell, const DIRECTION &direction) const {
  return cell.checkDirection(direction);
}

bool Board::IsWallPossible(const Cell &cell, const DIRECTION &direction) const {

}

bool Board::IsMovePossible(const Position &start, const Position &end) const {
  if (!(0 < start.col < kBoardSize && 0 < start.row < kBoardSize && 0 < end.col < kBoardSize
      && 0 < end.row < kBoardSize))
    return false;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (end == Position{start.col + i, start.row + j}) return true;
    }
  }
  return false;
}

void Board::PlaceWall(Position case1,Position case2,DIRECTION dir){
    cells_[case1.row][case1.col].setWall(dir);
    cells_[case1.row][case1.col].setWall(dir);
    walls_[case1.row*2+1][case1.col*2]=true;
    walls_[case2.row*2+1][case2.col*2]=true;
}

void Board::Movement(const Position &p, bool pw) {
  if (pw) {
    cells_[p.row][p.col].setPawn();
  } else {
    cells_[p.row][p.col].removePawn();
    cells_[p.row][p.col] = Cell{};
  }
}

std::ostream &operator<<(ostream &os, const Board &board) {
  return os << static_cast<std::string>(board) << "\n"; // we do not need to flush the output here, \n is enough
}

Board::operator std::string() const {
  return GetBoardString();
}
