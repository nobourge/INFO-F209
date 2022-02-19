#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_ia_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_ia_H_

#include"Player.h"

#include<iostream>
#include<random>
using namespace std;

class Ia:public Player{
    int nrOfWalls=10;
    Position IAPos;
    DIRECTION dr=SOUTH; //by default the IA will be going in SOUTH
public:
    Ia(Position,DIRECTION);
    Position playIAMove(bool=true) override;
    Position getPlayerPos();
    void setPlayerPosition(Position);
    bool hasWon();

};

#endif