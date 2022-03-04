/*
board.cpp
TODO do the description
*/
#include "board.h"
#include <iostream>

using namespace std;

///
/// \param pawns_
/// \param wallsPosition
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

  std::cout<<GetWallsSerialization()<<std::endl;
  std::string test = GetWallsSerialization();
  std::cout<<GetWallFromWallSerialization(test)[0].row<<std::endl;

}

Board::Board(std::string) {
  //"to do or not to do this is the question" -Shakespear
}

void Board::SaveToDB() const {
  // DataBase::GetInstance()
  if (pawns_.size() > 2) {
    DataBase::GetInstance()->InsertBoard(4,  GetWallsSerialization(),
    GetPositionSerialization(pawns_[0]->getPlayerPos()), pawns_[0]->GetNrOfWalls(),
    GetPositionSerialization(pawns_[1]->getPlayerPos()), pawns_[1]->GetNrOfWalls(),
    GetPositionSerialization(pawns_[2]->getPlayerPos()), pawns_[2]->GetNrOfWalls(),
    GetPositionSerialization(pawns_[3]->getPlayerPos()), pawns_[3]->GetNrOfWalls());
  }else{
    DataBase::GetInstance()->InsertBoard(2,  GetWallsSerialization(),
        GetPositionSerialization(pawns_[0]->getPlayerPos()), pawns_[0]->GetNrOfWalls(),
        GetPositionSerialization(pawns_[1]->getPlayerPos()), pawns_[1]->GetNrOfWalls());
  }
}

std::string Board::GetSerializedString() const {
  return {};
}

std::string Board::GetWallsSerialization() const {
  std::string serializedString = "";
  for (int row = 0; row<kBoardSize*2-1; row++) {
    for (int col = 0; col<kBoardSize*2-1; col++) {
      if (walls_[row][col]) serializedString = serializedString + GetPositionSerialization({col, row}) + "|";
    }
  }
  return serializedString;
}

std::string Board::GetPositionSerialization(const Position position) const {
  return std::to_string(position.col) + "," + std::to_string(position.row);
}

std::vector<Position> Board::GetWallFromWallSerialization(std::string serializedWalls) {
  std::vector<Position> res;
  std::string currentWall = serializedWalls.substr(0, serializedWalls.find("|"));
  while (!currentWall.empty()) {
    res.push_back(GetPositionFromPositionSerialization(currentWall));
    serializedWalls.erase(0, serializedWalls.find("|") + 1);
    currentWall = serializedWalls.substr(0, serializedWalls.find("|"));
  }
  return res;
}

Position Board::GetPositionFromPositionSerialization(std::string serializedPosition) {
  std::string col = serializedPosition.substr(0, serializedPosition.find(","));
  serializedPosition.erase(0, serializedPosition.find(",") + 1);
  std::string row = serializedPosition;
  return Position{std::stoi(col), std::stoi(row)};
}
///
/// \return
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
  for (int row = 1; row < 10; row++) {
    boardString += std::to_string(row);
    boardString += "   ";
  }

  return boardString;

}

///
/// \param firstCell
/// \param secondCell
/// \return
bool Board::GetWallBetween(const Cell &firstCell, const Cell &secondCell) const {
  if (! firstCell.isNeighbour(secondCell)) return false;
  std::pair<int, int> deltas = firstCell.getPos().diff(secondCell.getPos());  // first is col
  if (deltas.first != 0) {
    return (deltas.first > 0) ? firstCell.checkDirection(NORTH) : firstCell.checkDirection(SOUTH);
  } else {
    return (deltas.second > 0) ? firstCell.checkDirection(WEST) : firstCell.checkDirection(EAST);
  }
}

///
/// \param cell
/// \param direction
/// \return
bool Board::GetWallBetween(const Cell &cell, const DIRECTION &direction) const {
  return cell.checkDirection(direction);
}

///
/// \param position
/// \return
Cell Board::GetCellAtPosition(const Position &position) const {
  return cells_[position.row][position.col];
}

///
/// \param position
/// \param direction
/// \return
bool Board::HasReachedEnd(const Position position, const DIRECTION direction) const {
  switch(direction) {
    case NORTH:
      if (position.row == 0) return true;
      break;
    case EAST:
      if (position.col == kBoardSize - 1) return true;
      break;
    case SOUTH:
      if (position.row == kBoardSize - 1) return true;
      break;
    case WEST:
      if (position.col == 0) return true;
      break;
  }
  return false;
}

///
/// \param path
/// \param goal
/// \return
bool Board::HasPathToEnd(std::vector<Position> path, const DIRECTION goal) {
  bool deadEnd;
  std::vector<Position> visited;
  visited.push_back(path.front());

  while (! path.empty()) {
    if (HasReachedEnd(path.back(), goal)) return true;
    deadEnd = true;
    for (int direction = 0 ; direction < 4 ; direction++) {
      if (std::find(visited.begin(), visited.end(), path.back() + static_cast<DIRECTION>(direction) ) == visited.end()
          && IsMovePossible(path.back(), path.back() + static_cast<DIRECTION> (direction))){


        visited.push_back(path.back() + static_cast<DIRECTION> (direction));
        path.push_back(path.back() + static_cast<DIRECTION> (direction));
        deadEnd = false;
      }
    }
    if (deadEnd) path.pop_back();
  }
  return false;
}

///
/// \param firstCell
/// \param secondCell
/// \param direction
/// \return
bool Board::IsWallPossible(const Position firstCell, const Position secondCell, const DIRECTION direction) {
  Position firstOpposite=getOppositeCell(firstCell,direction);
  Position secondOpposite=getOppositeCell(secondCell,direction);

  cells_[firstCell.row][firstCell.col].setWall(direction);
  cells_[secondCell.row][secondCell.col].setWall(direction);
  cells_[firstOpposite.row][firstOpposite.col].setWall(getOpposite(direction));
  cells_[secondOpposite.row][secondOpposite.col].setWall(getOpposite(direction));

  for (auto pawn : pawns_ ) {
    if (! HasPathToEnd({pawn->getPlayerPos()}, pawn->getGoal())){
      cells_[firstCell.row][firstCell.col].unsetWall(direction);
      cells_[secondCell.row][secondCell.col].unsetWall(direction);
      cells_[firstOpposite.row][firstOpposite.col].unsetWall(getOpposite(direction));
      cells_[secondOpposite.row][secondOpposite.col].unsetWall(getOpposite(direction));
      return false;
    }
  }
  return true;
}

///
/// \param start
/// \param end
/// \return
bool Board::IsMovePossible(const Position &start, const Position &end) const {
  if (end.IsOutOfBoundaries() || GetWallBetween(GetCellAtPosition(start), GetCellAtPosition(end))) return false;
  return GetCellAtPosition(start).isNeighbour(end) ? true : false;
}

///

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

///
/// \param case1
/// \param case2
/// \param dir
void Board::PlaceWall(Position case1, Position case2, DIRECTION dir) {
  if (! IsWallPossible(case1, case2, dir)) return;
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

///
/// \param pos
/// \param dr
/// \return
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

///
/// \param dr
/// \return
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

/// moves a pawn to a valid asked position
/// \param start
/// \param end
void Board::Movement(const Position start, const Position end) {
  cells_[end.row][end.col].setPawn(GetCellAtPosition(start).getPawn());
  cells_[start.row][start.col].removePawn();
}

/// \param os
/// \param board
/// \return
std::ostream &operator<<(ostream &os, const Board &board) {
  return os << static_cast<std::string>(board) << "\n"; // we do not need to flush the output here, \n is enough
}

///
/// \return
Board::operator std::string() const {
  return GetBoardString();
}
