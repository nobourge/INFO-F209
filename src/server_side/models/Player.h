#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_Player_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_Player_H_

#include"position.h"
#include"memory.h"
#include"common.h"
#include<iostream>
#include"translator.h"

class Player{
    int nbWalls=10;
    Position playerPos;
    DIRECTION dr;


public:
    Player(){}
    Player(Position,DIRECTION);
    bool isTurnOver();
    virtual bool hasWon();
    Position playMove(DIRECTION);
    Position getPlayerPos();
    void setPlayerPosition(Position);
    Position calculateDirection(char,Position,DIRECTION);
    pair<Position,Position> placeWall(std::string);
    virtual Position playIAMove(bool=true){return {0,0};};
    std::string getMessage();
    DIRECTION getGoal() const;
};

#endif
