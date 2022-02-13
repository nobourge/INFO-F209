#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_POSITION_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_POSITION_H_

#include <utility>

struct Position {
  int col, row;

  bool operator==(const Position &pos) const {
    if (this->row == pos.row && this->col == pos.col) {
      return true;
    } else {
      return false;
    }
  }

  std::pair<int, int> diff(const Position &) const; // outputs a pair of deltaCol
                                                    // and deltaRow
                                                    // {1,0} -> W
                                                    // {0,1} -> N
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_POSITION_H_
