#include <iostream>
#include "models/board.h"
#include "models/position.h"
int main() {
  std::cout<<std::endl;
  std::vector<Position> pawn {Position{1,2}};
  std::vector<Position> walls{Position{0,1}};
  Board test (pawn, walls);
  std::cout<<test.getBoardString()<<std::endl;

  std::cout << "Hello, World!" << std::endl;
  return 0;
}
