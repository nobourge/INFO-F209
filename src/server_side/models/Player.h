#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_Player_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_Player_H_

#include"position.h"
#include"memory.h"
#include"board.h"

class Player{
    int nbWalls;
    Position finishLine;
    // std::shared_ptr board=make_shared<Board>();


public:
    Player();
    bool isTurnOver();
    bool hasWon();
    std::string getMessage();
};

#endif