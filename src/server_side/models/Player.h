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
    Player(Position,DIRECTION);
    bool isTurnOver();
    bool hasWon();
    Position playMove(DIRECTION);
    Position getPlayerPos();
    void setPlayerPosition(Position);
    Position calculateDirection(char);
    pair<Position,Position> placeWall(std::string);
    std::string getMessage();
    DIRECTION getGoal() const;
};

#endif
