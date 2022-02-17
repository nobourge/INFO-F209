#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_POSITION_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_POSITION_H_

#include <utility>
#include "common.h"
#include "serializable.h"
#include <iostream>

struct Position: public Serializable{
  int col, row;

  Position(int col, int row);

  std::unique_ptr<crow::json::wvalue> Serialize() override;

  bool operator==(const Position &pos) const;

  std::pair<int, int> diff(const Position &) const; // outputs a pair of deltaRow
                                                    // and deltaCol

  bool IsOutOfBoundaries(const int &low=0, const int &high=kBoardSize) const;

  Position operator+(const DIRECTION);

};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_POSITION_H_
