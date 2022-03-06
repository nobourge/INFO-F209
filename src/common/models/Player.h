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
  int nbWalls = 10;
  Position playerPos;
  DIRECTION dr;
  int score = 0;

  std::optional<object_id_t> user_;

public:
  Player(std::optional<object_id_t> user_id) : user_(user_id) {}
  Player(Position, DIRECTION, int = 10);
  // direction of first player is always NORTH, second SOUTH, third WEST,
  // fourth EAST
  bool isTurnOver();
  virtual bool hasWon();
  Position playMove(DIRECTION);
  Position getPlayerPos();
  void setPlayerPosition(Position);
  Position calculateDirection(char, Position, DIRECTION);
  pair<Position, Position> placeWall(std::string);
  virtual Position playIAMove(bool = true) { return {0, 0}; };
  void increaseScore(int = 5);
  int getScore();
  DIRECTION getGoal() const;

  crow::json::wvalue Serialize() {
    crow::json::wvalue output;

    output["number_of_walls"] = nbWalls;
    output["direction"] = static_cast<int>(dr);
    output["score"] = score;
    output["position"] = std::move(*playerPos.Serialize());

    if (user_.has_value()) {
      output["user"] = *user_;
    }

    return output;
  }

  static std::optional<Player> FromJson(const crow::json::rvalue &json) {
    Player player{};
    try {
      player.nbWalls = json["number_of_walls"].i();

      auto pos = Position::FromJson(json["position"]);
      if (!pos.has_value()) {
        return {};
      }
      player.playerPos = *pos;

      player.dr = static_cast<DIRECTION>(json["direction"].i());
      player.score = json["score"].i();

    } catch(...) {
      return {};
    }
    return player;
  }

  void DecNrOfWalls();
  int GetNrOfWalls();

  virtual bool IsAI() { return false; };

private:
  Player() : playerPos(), user_(0) {};
};

#endif
