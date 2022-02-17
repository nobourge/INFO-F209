/*
board.cpp
TODO do the description
*/
#include "board.h"
#include <iostream>

using namespace std;

Board::Board(std::vector<std::shared_ptr<Player>> pawns_, std::vector<Position> wallsPosition) : pawns_{pawns_} {
  // setting up the board by trusting the positions to be possible

  for (int row = 0; row < kBoardSize * 2 - 1; row++) { // initializing the two arrays
    for (int col = 0; col < kBoardSize * 2 - 1; col++) {
      if (row < kBoardSize && col < kBoardSize) cells_[row][col].setPos({col, row});
      walls_[row][col] = false;
    }
  }

  auto lambda = [] (const Position position, std::shared_ptr<Player> pawn, array<array<Cell, kBoardSize>, kBoardSize> &cells) {cells[position.row][position.col].setPawn(pawn);};
  for (std::shared_ptr<Player> pawn : pawns_) lambda(pawn->getPlayerPos(), pawn, cells_);

  // for (Position pos : pawns_) {
  //   cells_[pos.row][pos.col].setPawn();
  //   pawns_.push_back(pos);
  // }

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
    return (deltas.first > 0) ? firstCell.checkDirection(NORTH) : firstCell.checkDirection(SOUTH);
  } else {
    return (deltas.second > 0) ? firstCell.checkDirection(WEST) : firstCell.checkDirection(EAST);
  }
}

bool Board::GetWallBetween(const Cell &cell, const DIRECTION &direction) const {
  return cell.checkDirection(direction);
}

Cell Board::GetCellAtPosition(const Position &position) const {
  return cells_[position.row][position.col];
}

bool Board::IsWallPossible(std::vector<Position> path, const DIRECTION direction) const {
  // bfs pathfinding algorithm
  if (direction % 2 == 0 && path.front().row == pow(9, (int)(direction)) - 1) {
    return true;
  } else if (direction % 2 != 0 && path.front().col == pow(9, (int)(direction) -1) - 1) {
    return true;
  };

  for (Position cellPosition : path) {
    for (int dir = 0; dir<kNumberOfDirections; dir++){
      if (GetWallBetween(GetCellAtPosition(cellPosition), GetCellAtPosition(cellPosition + direction))) {
        path.push_back(cellPosition);
        IsWallPossible(path, direction);
      }
      if (path.size() > 0) {
        path.erase(path.begin());
        IsWallPossible(path, direction);
      }
    }
  }

  return false;
}

bool Board::IsMovePossible(const Position &start, const Position &end) const {
  if (end.IsOutOfBoundaries() || GetWallBetween(GetCellAtPosition(start), GetCellAtPosition(end))) return false;
  return (GetCellAtPosition(start).isNeighbour(end)) ? true : false;
}

void Board::randomWallPlacement(){
  //Method used for our first game mode.
  int x=0+(rand()%kBoardSize);
  int y=0+(rand()%kBoardSize);
  DIRECTION dr=static_cast<DIRECTION>(rand()%4);
  Position cell1;
  Position cell2;
  if(dr==NORTH || dr==SOUTH){
    cell1={x,y};
    cell2={x+1,y};
  }else{
    cell1={x,y};
    cell2={x,y-1};
  }
  PlaceWall(cell1,cell2,dr);

}

void Board::PlaceWall(Position case1, Position case2, DIRECTION dir) {
      cells_[case1.row][case1.col].setWall(dir);
      cells_[case2.row][case2.col].setWall(dir);
      Position case3=getOppositeCell(case1,dir);
      Position case4=getOppositeCell(case2,dir);
      cells_[case3.row][case3.col].setWall(getOpposite(dir));
      cells_[case4.row][case4.col].setWall(getOpposite(dir));
      if(dir==SOUTH){
        walls_[case1.row*2+1][case1.col*2]=true;
        walls_[case2.row*2+1][case2.col*2]=true;
      }else if(dir==NORTH){
        walls_[case1.row*2-1][case1.col*2]=true;
        walls_[case2.row*2-1][case2.col*2]=true;
      }
      else if(dir==EAST){
        walls_[case1.row*2][case1.col*2+1]=true;
        walls_[case2.row*2][case2.col*2+1]=true;
      }else{
        walls_[case1.row*2][case1.col*2-1]=true;
        walls_[case2.row*2][case2.col*2-1]=true;
      }
}

Position Board::getOppositeCell(Position pos,DIRECTION dr){
    Position newPos;
    if(dr==NORTH){
      newPos={pos.col,pos.row-1};
    }else if(dr==SOUTH){
      newPos={pos.col,pos.row+1};
    }else if(dr==EAST){
      newPos={pos.col+1,pos.row};
    }else{
      newPos={pos.col-1,pos.row};
    }
    return newPos;
}

DIRECTION Board::getOpposite(DIRECTION dr){
  DIRECTION newdr;
  if(dr==NORTH){
    newdr=SOUTH;
  }else if(dr==SOUTH){
    newdr=NORTH;
  }else if(dr==EAST){
    newdr=WEST;
  }else{
    newdr=EAST;
  }
  return newdr;
}


void Board::Movement(const Position start, const Position end) {
  cells_[end.row][end.col].setPawn(GetCellAtPosition(start).getPawn());
  cells_[start.row][start.col].removePawn();
}

// void Board::Movement(const Position &p, bool pw) {
//   if (pw) {
//     cells_[p.row][p.col].setPawn();
//   } else {
//     cells_[p.row][p.col].removePawn();
//     cells_[p.row][p.col] = Cell{};
//   }
// }

std::ostream &operator<<(ostream &os, const Board &board) {
  return os << static_cast<std::string>(board) << "\n"; // we do not need to flush the output here, \n is enough
}

Board::operator std::string() const {
  return GetBoardString();
}
