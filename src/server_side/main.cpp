#define CROW_MAIN
#define CROW_JSON_USE_MAP

#include <iostream>
#include "view_controllers/api/v1/v1_api.h"
//#include "models/board.h"
#include "models/position.h"
#include "models/Game.h"

int main() {
  V1Api api;
  api.Run();

  Game gameOn = Game(); //Normally this gets turned on by the server when the user wants to begin a game.
  //Server has to start the game and manage the players connection etc.
  //TODO server stuff
//  gameOn.StartTheGame();
//  while (gameOn.gameOnGoing()) {
//
//  }

  return 0;
}