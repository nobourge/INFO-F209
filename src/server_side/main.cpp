#define CROW_MAIN

#include <iostream>
#include "view_controllers/api/base_quoridor_api.h"
#include "models/board.h"
#include "models/position.h"
#include "models/Game.h"



int main() {

   BaseQuoridorApi api;

   api.Run();



  Game gameOn = Game(); //Normally this gets turned on by the server when the user wants to begin a game.
  //Server has to start the game and manage the players connection etc.
  //TODO server stuff
  gameOn.StartTheGame();
  while (gameOn.gameOnGoing()) {

  }


  
  return 0;
}