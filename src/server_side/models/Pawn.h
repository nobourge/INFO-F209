#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_Pawn_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_Pawn_H_


#include"position.h"

class Pawn{
    
public:
  Pawn();
  void Move(Position);
};

#endif