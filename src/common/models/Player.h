#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_Player_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_Player_H_

#include "../constants.h"
#include "common.h"
#include "memory.h"
#include "position.h"
#include "translator.h"
#include <iostream>
#include <optional>

class Player {
  int n_walls_ = 10;
  Position position_;
  DIRECTION direction_;
  int score_ = 0;
  uuid_t uuid_;

private:
  std::optional<object_id_t> user_id_;

public:
  const uuid_t &GetUuid() const;
  Player(std::optional<object_id_t> user_id);
  Player(Position, DIRECTION, int = 10);
  // direction of first player is always NORTH, second SOUTH, third WEST,
  // fourth EAST
  void SetUser(const optional<uint32_t> &user);
  object_id_t GetUniqueGameId();
  const optional<uint32_t> &GetUserId() const;
  bool isTurnOver();
  virtual bool hasWon();
  Position playMove(DIRECTION);
  Position getPlayerPos();
  void setPlayerPosition(Position);
  static Position calculateDirection(char, const Position&, DIRECTION);
  pair<Position, Position> placeWall(std::string);
  virtual Position playIAMove(bool = true) { return {0, 0}; };
  void increaseScore(int = 5);
  int getScore();
  DIRECTION getGoal() const;

  crow::json::wvalue Serialize();

  static std::optional<Player> FromJson(const crow::json::rvalue &json);

  void DecNrOfWalls();
  int GetNrOfWalls() const;

  virtual bool IsAI() { return false; };

private:
  Player() : position_(), user_id_(0) {};
};

#endif
