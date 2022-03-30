#include "Player.h"
#include "../utils.h"
#include "position.h"
#include <iostream>
#include <utility>
#include <uuid/uuid.h>

using namespace std;

Player::Player(Position position, DIRECTION direction, int n_walls)
    : Player(0) {
  position_ = std::move(position);
  direction_ = direction;
  n_walls_ = n_walls;
}

///
/// \return
bool Player::isTurnOver() { return true; }

///
/// \return
bool Player::hasWon() {
  return (direction_ == NORTH && position_.row == 0) ||
         (direction_ == SOUTH && position_.row == kBoardSize - 1) ||
         (direction_ == EAST && position_.col == kBoardSize - 1) ||
         (direction_ == WEST && position_.col == 0);
}

///
/// \param placement
/// \return
pair<Position, Position> Player::placeWall(string placement) {
  // Cut the a1->a2->N in a1 , a2 and N;
  std::string delimiter = "->";
  std::string case1 = placement.substr(0, placement.find(delimiter));

  placement.erase(0, placement.find(delimiter) + delimiter.length());
  string case2 = placement.substr(0, placement.find(delimiter));

  // Translate the move a1 in Position;
  Position move1 = Translator::Get().translateMove(case1);
  Position move2 = Translator::Get().translateMove(case2);

  pair<Position, Position> ret = {move1, move2};
  return ret;
}

///
/// \param direction
/// \return
Position Player::playMove(DIRECTION direction) {
  Position pos;

  if (direction == NORTH) {
    pos = calculateDirection('F', position_, direction_);

  } else if (direction == EAST) {
    pos = calculateDirection('R', position_, direction_);

  } else if (direction == WEST) {
    pos = calculateDirection('L', position_, direction_);
  } else if (direction == SOUTH) {
    pos = calculateDirection('B', position_, direction_);
  }
  return pos;
}

///
/// \param c
/// \param Pos
/// \param dir
/// \return
Position Player::calculateDirection(char c, const Position &Pos,
                                    DIRECTION dir) {
  Position coup;
  if (c == 'F') {
    if (dir == NORTH) {
      coup = Position{Pos.col, Pos.row - 1};
    } else if (dir == EAST) {
      coup = Position{Pos.col + 1, Pos.row};
    } else if (dir == SOUTH) {
      coup = Position{Pos.col, Pos.row + 1};
    } else {
      coup = Position{Pos.col - 1, Pos.row};
    }
  } else if (c == 'R') {
    if (dir == NORTH) {
      coup = Position{Pos.col + 1, Pos.row};
    } else if (dir == EAST) {
      coup = Position{Pos.col, Pos.row + 1};
    } else if (dir == SOUTH) {
      coup = Position{Pos.col - 1, Pos.row};
    } else {
      coup = Position{Pos.col, Pos.row - 1};
    }
  } else if (c == 'L') {
    if (dir == NORTH) {
      coup = Position{Pos.col - 1, Pos.row};
    } else if (dir == EAST) {
      coup = Position{Pos.col, Pos.row - 1};
    } else if (dir == SOUTH) {
      coup = Position{Pos.col + 1, Pos.row};
    } else {
      coup = Position{Pos.col, Pos.row + 1};
    }
  } else {
    if (dir == NORTH) {
      coup = Position{Pos.col, Pos.row + 1};
    } else if (dir == EAST) {
      coup = Position{Pos.col - 1, Pos.row};
    } else if (dir == SOUTH) {
      coup = Position{Pos.col, Pos.row - 1};
    } else {
      coup = Position{Pos.col + 1, Pos.row};
    }
  }
  return coup;
}

void Player::increaseScore(int newscore) { score_ += newscore; }

int Player::getScore() { return score_; }

///
/// \param newPos
void Player::setPlayerPosition(Position newPos) {
  position_ = std::move(newPos);
}

///
/// \return
Position Player::getPlayerPos() { return position_; }

///
/// \return
DIRECTION Player::getGoal() const { return direction_; }

void Player::DecNrOfWalls() { n_walls_--; }

int Player::GetNrOfWalls() const { return n_walls_; }

const optional<uint32_t> &Player::GetUserId() const { return user_id_; }

void Player::SetUser(const optional<uint32_t> &user) { user_id_ = user; }

Player::Player(std::optional<uint32_t> user_id) : user_id_(user_id) {
  uuid_generate_random(uuid_);
}

crow::json::wvalue Player::Serialize() {
  crow::json::wvalue output;

  output["number_of_walls"] = n_walls_;
  output["direction"] = static_cast<int>(direction_);
  output["score"] = score_;
  output["position"] = std::move(*position_.Serialize());

  if (user_id_.has_value()) {
    output["user"] = *user_id_;
  }

  // UUID is 36 chars (+ "\0")
  char *uuid = new char[UUID_LEN + 1];
  uuid_unparse(uuid_, uuid);
  output["uuid"] = uuid;

  return output;
}

std::optional<Player> Player::FromJson(const crow::json::rvalue &json) {
  Player player{};
  try {
    player.n_walls_ = json["number_of_walls"].i();

    auto pos = Position::FromJson(json["position"]);
    if (!pos.has_value()) {
      return {};
    }
    player.position_ = *pos;

    player.direction_ = static_cast<DIRECTION>(json["direction"].i());
    player.score_ = json["score"].i();

    if (json.has("user")) {
      player.user_id_ = json["user"].i();
    }
    uuid_parse(json["uuid"].s().begin(), player.uuid_);

  } catch (...) {
    return {};
  }
  return player;
}

const uuid_t &Player::GetUuid() const { return uuid_; }
