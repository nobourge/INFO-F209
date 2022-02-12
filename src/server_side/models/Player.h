#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_Player_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_Player_H_

#include"position.h"
#include"memory.h"
#include"board.h"
#include"common.h"

class Player{
    int nbWalls=10;
    Position finishLine;
    Position playerPos;
    DIRECTION dr;


public:
    Player(Position,Position,DIRECTION);
    bool isTurnOver();
    bool hasWon();
    Position playCoup();
    Position getPlayerPos();
    void setPlayerPosition(Position);
    Position calculateDirection(char);

    std::string getMessage();
};

#endif