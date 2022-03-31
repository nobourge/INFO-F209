#include "position.h"
#include <iostream>
#include <vector>
#include "common.h"

using namespace std;

class Translator{ // singleton
  Translator() {}
  static Translator instance;
  DIRECTION GetOppositeDirection(DIRECTION);  // already implemented in board but lack of idea to make it work atm
public:

  static Translator& Get();

  bool verifyMove(string,vector<char>);
  bool verifyNumber(string,vector<string>);
  Position translateMove(string,int=9);
  std::string PositionToMove(const Position, int=9);

  std::string PositionToWallMove(Position firstWall, Position secondWall);
  std::string PositionToPawnMove(DIRECTION movementDirection, DIRECTION winningDirection);
};
