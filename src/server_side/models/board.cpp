/*
board.cpp
TODO do the description
*/
#include "board.h"

Board::Board(std::vector<Position> pawnsPosition, std::vector<Position> wallsPosition) {
  // setting up the board by trusting the positions to be possible

  for (int row=0; row<kBoardSize*2;row++) { // initializing the two arrays
    for (int col=0; col<kBoardSize*2;col++) {
      if (row<kBoardSize && col<kBoardSize) cells_[row][col] = Cell {};
      walls_[row][col] = false;
    }
  }

  for (Position pos : pawnsPosition) {
    cells_[pos.row][pos.col].setPawn();
  }

  for (Position pos : wallsPosition) {
    walls_[pos.row][pos.col] = true;
  }
}

std::string Board::getBoardString() const {
  std::string boardString;
  for (int row=0; row<kBoardSize*2-1; row++) {
    for (int col=0; col<kBoardSize*2-1; col++) {
      if (row%2==0 && col%2==0){  // printing the cells
        if(col==0){
          boardString+= kAlphabet[row/2];
          boardString+=" ";
        }
        if (cells_[row/2][col/2].isPawn()){
          boardString+=" p "; // player
        }else{
          boardString+="   "; // blank
        }
      }

      if (col==0 && row%2!=0) { // inter cell space
        boardString+= "  "; // adding space to align with alphabet
      }
      if (walls_[row][col]) {
        boardString+="━━━"; // wall
      }else{
        if (row%2!=0) {
          if (col%2==0) {
            boardString+="┄┄┄";  //using pretty dash lines for the print unsure
                                 //about portability
          }else{
            boardString+="┆";
          }
        }else if(col%2!=0){
          boardString+="┆";
        }
      }
    }
    boardString+='\n';
  }

  // adding the numbers on the bottom row
  boardString+= "   ";
  for (int row=0;row<9;row++){
    boardString+=std::to_string(row);
    boardString+= "   ";
  }

  return boardString;

}

bool Board::isWallPossible(Position pos) const {
  return true;  // placeholder for now
}

bool Board::isMovePossible(Position start, Position end) const {
  if (!(0<start.row<kBoardSize && 0<start.col<kBoardSize && 0<end.row<kBoardSize
    && 0<end.col<kBoardSize)) return false;
    for (int i=-1;i<=1;i++) {
      for (int j=-1;j<=1;j++) {
        if (end == Position{start.row+i, start.col+j}) return true;
      }
    }
    return false;
  }