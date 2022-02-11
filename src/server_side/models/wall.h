//
// Created by Anton Romanova on 11/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_WALL_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_WALL_H_

#include<iostream>
#include"common.h"

class Wall {
public:

    Wall();

    bool isMovePossible(DIRECTION);

    void placeWall(DIRECTION);
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_WALL_H_
