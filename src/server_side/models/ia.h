#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_ia_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_ia_H_

#include"Player.h"

#include<iostream>
#include<random>

using namespace std;

class Ia:public Player{
public:
    Ia(Position,DIRECTION=SOUTH);
    bool IsAI(){return true;};
    Position playIAMove(bool=true);
    bool hasWon() override;
  };

#endif
