#include "Player.h"
#include "position.h"
#include <iostream>
#include <utility>

using namespace std;

Player::Player(Position playerPos, DIRECTION dr, int nbWalls)
    : playerPos(std::move(playerPos)), dr(dr), nbWalls{nbWalls} {}

///
/// \return
bool Player::isTurnOver() { return true; }

///
/// \return
bool Player::hasWon() {
  return (dr == NORTH && playerPos.row == 0) ||
         (dr == SOUTH && playerPos.row == kBoardSize - 1) ||
         (dr == EAST && playerPos.col == kBoardSize - 1) ||
         (dr == WEST && playerPos.col == 0);
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
    pos = calculateDirection('F', playerPos, dr);

  } else if (direction == EAST) {
    pos = calculateDirection('R', playerPos, dr);

  } else if (direction == WEST) {
    pos = calculateDirection('L', playerPos, dr);
  } else if (direction == SOUTH) {
    pos = calculateDirection('B', playerPos, dr);
  }
  return pos;
}

///
/// \param c
/// \param Pos
/// \param dir
/// \return
Position Player::calculateDirection(char c, const Position& Pos, DIRECTION dir) {
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

void Player::increaseScore(int newscore) { score += newscore; }

int Player::getScore() { return score; }

///
/// \param newPos
void Player::setPlayerPosition(Position newPos) { playerPos = std::move(newPos); }

///
/// \return
Position Player::getPlayerPos() { return playerPos; }

///
/// \return
DIRECTION Player::getGoal() const { return dr; }

void Player::DecNrOfWalls() { nbWalls--; }

int Player::GetNrOfWalls() const { return nbWalls; }

const optional<uint32_t> &Player::GetUserId() const { return user_; }

void Player::SetUser(const optional<uint32_t> &user) { user_ = user; }
