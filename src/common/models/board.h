/*
 board.h
 TODO: Add Description.
*/

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_

#include "cell.h"
#include "database.h"
#include "position.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <optional>
#include <ostream>
#include <random>
#include <string>
#include <vector>

class UserClient;

class Board {
public:
  Board(const std::vector<std::shared_ptr<Player>>&, const std::vector<Position>&);

  // should be implementing by inheriting DatabaseCompatible
//  void SaveToDB(object_id_t board_id = 0) const;
  // static std::optional<Board> InitFromDB(object_id_t game_id);

  static std::string GetPositionSerialization(const Position&);
  std::string GetWallsSerialization() const;

  static std::vector<Position> GetWallFromWallSerialization(std::string);
  static Position GetPositionFromPositionSerialization(std::string);

  bool GetWallBetween(const Cell &, const Cell &) const;
  bool GetWallBetween(const Cell &,
                      const DIRECTION &) const; // might be faster in some cases

  Cell GetCellAtPosition(const Position &) const;

  bool HasReachedEnd(const Position, const DIRECTION) const;
  bool HasPathToEnd(std::vector<Position>, const DIRECTION);

  bool IsWallPossible(const Position, const Position, const DIRECTION);
  bool IsMovePossible(const Position &, const Position &) const;

  std::vector<DIRECTION> PossiblePawnHops(const Position, const DIRECTION);
  void Movement(const Position, const Position);
  void PlaceWall(Position, Position, DIRECTION);

  friend std::ostream &operator<<(std::ostream &, const Board &);

  std::string GetBoardString() const;

  void RandomWallPlacement();
  DIRECTION GetOpposite(DIRECTION);
  Position GetOppositeCell(Position, DIRECTION);

  static optional<Board>
  FromJson(const crow::json::rvalue &json,
           const unordered_map<string, shared_ptr<Player>> &game_players);

  explicit operator std::string() const;

  std::array<std::array<bool, kBoardSize * 2 - 1>, kBoardSize * 2 - 1>
  GetWalls();

  crow::json::wvalue Serialize();

  std::vector<std::pair<int, int>> GetAllPlayersPos();
  
  std::vector<std::pair<int, int>> GetAllWallsPos();

private:
  std::vector<std::shared_ptr<Player>> pawns_ = {};
  std::array<std::array<Cell, kBoardSize>, kBoardSize> cells_ = {};
  std::array<std::array<bool, kBoardSize * 2 - 1>, kBoardSize * 2 - 1>
      walls_ = {}; // same problem as in cell.h no need
  // for a class
};

#endif // QUORIDOR_SRC_SERVER_SIDE_MODELS_BOARD_H_
