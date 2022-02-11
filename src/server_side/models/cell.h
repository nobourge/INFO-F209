//
// Cell.h
// TODO:Description

#include<iostream>
#include"position.h"
#include"wall.h"
#include"const.h"
#include"Pawn.h"
#include<memory>
#include<vector>

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_CELL_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_CELL_H_

class Cell {
    std::unique_ptr<Pawn> pawn;
    std::vector<std::shared_ptr<Wall>> walls;
    Position pos;
public:

    Cell();

    bool isPawn();
    void setPawn();
    bool checkDirection(DIRECTION);
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_CELL_H_
