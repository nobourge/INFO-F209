#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_Player_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_Player_H_

#include"position.h"
#include"memory.h"
#include"board.h"

class Player{
    int nbWalls=10;
    Position finishLine;
    Position playerPos;
    Board* board;
    // std::shared_ptr board=make_shared<Board>();


public:
    Player(Position,Position,Board*);
    ~Player(){delete board;}
    bool isTurnOver();
    bool hasWon();
    void playCoup();
    Position getPlayerPos();
    void setPlayerPosition(Position);
    std::string getMessage();
};

#endif