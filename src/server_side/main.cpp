#define CROW_MAIN

#include <iostream>
#include "views/api/quoridor_api.h"
#include "models/board.h"
#include "models/position.h"
#include "models/Game.h"



int main() {

  QuoridorAPI api;

  api.Run();



  Game gameOn = Game(); //Normally this gets turned on by the server when the user wants to begin a game.
  //Server has to start the game and manage the players connection etc.
  //TODO server stuff
  gameOn.StartTheGame();
  while (gameOn.gameOnGoing()) {

  }


   std::cout<<std::endl;
   std::vector<Position> pawn {Position{1,2}};
   std::vector<Position> walls{Position{0,1}};
   Board test (pawn, walls);
   std::cout<<test.GetBoardString()<<std::endl;


  return 0;
}