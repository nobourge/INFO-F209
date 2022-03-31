#include "Game.h"
#include "../utils.h"
#include <iostream>
#include <memory>
#include <utility>
#include <unordered_map>
#include <uuid/uuid.h>

using namespace std;

Game::Game() {
  p_board_ = std::make_unique<Board>(std::vector<std::shared_ptr<Player>>{}, std::vector<Position>{});
  game_on_ = true;
}

Game::Game(const std::vector<std::pair<Position, int>> &playersPair,
           int currentPlayerIndex, std::vector<Position> walls) {

  // if (players_.size>=2) We need at least 2 players_ to begin the game.
  int direction = 0;

  // not giving the pointer in parameter but making them here due to a previous
  // memory leak
  for (const auto &pair : playersPair) {
    players_.push_back(std::make_shared<Player>(
        pair.first, static_cast<DIRECTION>(direction), pair.second));
    direction++;
  }

  current_player_ = players_[0];

  game_on_ = true;
  p_board_ = std::make_unique<Board>(Board(players_, walls));

  // code for local testing on terminal
  // std::vector<std::string> test{"M->F", "M->F", "M->F", "M->F->L",
  // "W->a1->a2->S", "W->a2->a3->S"}; for (std::string move : test){
  //   PlayMove(move);
  //   cout<<board->GetBoardString()<<std::endl;
  // }
  // end of testing code
}

Game::Game(std::string gameName, int nrOfPlayers) : game_name_(gameName) {

  players_.push_back(std::make_shared<Player>(Position{4, 8}, NORTH));
  players_.push_back(std::make_shared<Player>(Position{4, 0}, SOUTH));

  if (nrOfPlayers == 4) {
    players_.push_back(std::make_shared<Player>(Position{8, 4}, WEST));
    players_.push_back(std::make_shared<Player>(Position{0, 4}, EAST));
  } else if (nrOfPlayers != 2) {
    throw std::invalid_argument("Invalid number of players");
  }

  game_on_ = true;
  current_player_ = players_[0];
  p_board_ = std::make_unique<Board>(players_, std::vector<Position>{});
}

// Game() // ia game constructor
// if(game_mode_==IA){
//   //If IA is on then we will have 1 Player vs 1 IA
//   players_.push_back(make_shared<Ia>(Position{4,0},SOUTH));
// }

// Game()  // randomwall game constructor

Game Game::StartNewGame(std::string gameName, int nrOfPlayers) {
  auto game = Game(gameName, nrOfPlayers);
  return Game(gameName, nrOfPlayers);
}

///
void Game::StartTheGame() {}

///

void Game::SwitchCurrentPlayer() {
  // First we check if the current player has won before we change the player at
  // the end of the turn
  if (HasCurrentPlayerWon()) {
    CalculateRanking();
    EndGame();
  }

  // system("clear"); //clears the terminal.

  if (game_mode_ == IA) {
    if (ia_player_) {
      current_player_ = players_[0];
      ia_player_ = false;
    } else {
      current_player_ = players_[1];
      ia_player_ = true;
      PlayIaMove();
    }
  } else if (game_mode_ == RandomWall) {
    p_board_->RandomWallPlacement();
  }

  auto current_player_in_vector =
      std::find_if(players_.begin(), players_.end(),
                   [&](const std::shared_ptr<Player> &player) {
                     return player->GetUserId() == current_player_->GetUserId();
                   });

  if (current_player_in_vector == players_.end() or ++current_player_in_vector == players_.end()) {
    current_player_in_vector = players_.begin();
  }
  current_player_ = *current_player_in_vector;
}

///

void Game::CalculateRanking() {
  // The player who won is going to get 100 points bonus.
  current_player_->increaseScore(100);

  vector<int> scores;
  for (auto x : players_) {
    scores.push_back(x->getScore());
  }

  // sort the vector non-increasing
  sort(scores.begin(), scores.end(), greater<int>());

  // if(scores.size()==2){
  //   db.InsertRanking(scores[0], scores[1]);
  // }else if(scores.size()==3){
  //   db.InsertRanking(scores[0], scores[1], scores[2]);
  // }else{
  //   db.InsertRanking(scores[0], scores[1], scores[2], scores[3]);
  // }

  // for(auto x:players_){
  //   db.UpdateUser(x->GetScore(), 1);
  // }
}

void Game::PlayIaMove() {
  bool on = false;
  string choose[2] = {"Movement", "Wall"};
  string choice = choose[rand() % 2];
  if (choice == "Movement") {
    while (!on) {
      Position coup = current_player_->playIAMove();
      cout << coup.row << " " << coup.col << " move" << endl;
      if (p_board_->IsMovePossible(current_player_->getPlayerPos(), coup)) {
        p_board_->Movement(current_player_->getPlayerPos(), coup);
        current_player_->setPlayerPosition(coup);
        on = true;
      } else {
        coup = current_player_->playIAMove(false);
        if (p_board_->IsMovePossible(current_player_->getPlayerPos(), coup)) {
          p_board_->Movement(current_player_->getPlayerPos(), coup);
          current_player_->setPlayerPosition(coup);
          on = true;
        }
      }
    }

  } else {
    // If IA places the wall then we will simply use the method from our first
    // game_mode_;
    p_board_->RandomWallPlacement();
  }
  SwitchCurrentPlayer();
}

///
/// \return
bool Game::HasCurrentPlayerWon() {
  // At the end of turn we check if the current_player_ has won the game.
  return current_player_->hasWon();
}

///

void Game::JoinGame() {
  // if (players_.size<4) Then the player can connect to the game.
}

///
/// \return
int Game::GetScore() {
  // The score for each player when the game is finished
  return 0;
}

///

void Game::EndGame() {
  // Server stuff
  //  p_board_->SaveToDB();
  game_on_ = false;
}

///
/// \return
bool Game::GameOnGoing() { return game_on_; }

std::optional<Error> Game::PlayMove(std::string move) {
  auto position_of_first_arrow = move.find("->");
  if (position_of_first_arrow == std::string::npos) {
    return "No arrow in move";
  }

  std::string first_input = move.substr(0, position_of_first_arrow);
  move.erase(0, position_of_first_arrow + 2);

  auto position_of_second_arrow = move.find("->");
  bool has_third_input = position_of_second_arrow == std::string::npos;

  std::string second_input = move.substr(0, position_of_second_arrow);
  move.erase(0, position_of_second_arrow + 2);

  if (first_input == "M") {
    DIRECTION direction;
    switch (second_input[0]) {
    case 'F':
      direction = NORTH;
      break;
    case 'B':
      direction = SOUTH;
      break;
    case 'L':
      direction = WEST;
      break;
    case 'R':
      direction = EAST;
      break;
    default:
      Error error;
      error += second_input[0];
      error += " is an invalid direction";
      return error;
    }

    Position playerMove = current_player_->playMove(direction);
    if (move.empty()) {
      if (p_board_->IsMovePossible(current_player_->getPlayerPos(),
                                   playerMove)) {
        p_board_->Movement(current_player_->getPlayerPos(), playerMove);
        current_player_->setPlayerPosition(playerMove);
        current_player_->increaseScore();
        SwitchCurrentPlayer();
      } else {
        return "Move is not possible";
      }
    } else if (second_input.size() == 1 &&
               !p_board_->GetWallBetween(
                   p_board_->GetCellAtPosition(current_player_->getPlayerPos()),
                   direction) &&
               p_board_->GetCellAtPosition(playerMove).isPawn()) {

      if (!has_third_input) {
        return "Must have a third input for a hop";
      }

      std::string third_input = move;

      DIRECTION second_direction;
      switch (third_input[0]) {
      case 'F':
        second_direction = NORTH;
        break;
      case 'B':
        second_direction = SOUTH;
        break;
      case 'L':
        second_direction = WEST;
        break;
      case 'R':
        second_direction = EAST;
        break;
      default:
        return "Invalid direction for third part of move";
      }

      std::vector<DIRECTION> possible_hops =
          p_board_->PossiblePawnHops(playerMove, direction);

      if (!possible_hops.empty()) {
        if (std::find(possible_hops.begin(), possible_hops.end(),
                      second_direction) != possible_hops.end()) {
          p_board_->Movement(current_player_->getPlayerPos(),
                             playerMove + second_direction);
          current_player_->setPlayerPosition(playerMove + second_direction);
          current_player_->increaseScore();
          SwitchCurrentPlayer();
        } else
          return "Wrong hop direction";
      } else {
        return "Impossible to hop over";
      }
    }

  } else if (first_input == "W") {
    if (current_player_->GetNrOfWalls() <= 0) {
      return "No more walls";
    }
    std::string third_input = move.substr(0, move.find("->"));
    move.erase(0, move.find("->") + 2);
    std::string fourth_input = move;
    move.erase(0, 1);

    if (!move.empty())
      return "Invalid move";

    DIRECTION wallDirection;
    switch (fourth_input[0]) {
    case 'N':
      wallDirection = NORTH;
      break;
    case 'S':
      wallDirection = SOUTH;
      break;
    case 'E':
      wallDirection = EAST;
      break;
    case 'W':
      wallDirection = WEST;
      break;
    default:
      return "Invalid wall direction";
    }

    pair<Position, Position> wall{Translator::Get().translateMove(second_input),
                                  Translator::Get().translateMove(third_input)};

    // Check is the placement is possible with isWallPossible();
    if (p_board_->IsWallPossible(wall.first, wall.second, wallDirection)) {
      p_board_->PlaceWall(wall.first, wall.second, wallDirection);
      current_player_->increaseScore();
      current_player_->DecNrOfWalls();
      SwitchCurrentPlayer();
    }

  } else {
    return "Invalid input";
  }
  return {};
}

///
/// \return
std::shared_ptr<Player> Game::GetCurrentPlayer() { return current_player_; }

crow::json::wvalue Game::GetGameJson() {
  crow::json::wvalue output;
  output["name"] = game_name_;

  if (p_board_ != nullptr) {
    output["board"] = std::move(p_board_->Serialize());
  }

  if (admin_player_ != nullptr) {
    output["admin"] = std::move(admin_player_->Serialize());
  }

  for (int i = 0; i < players_.size(); i++) {
    if (players_.at(i) != nullptr) {
      output["players_"][i] = std::move(players_.at(i)->Serialize());
    } else {
      output["players_"][i] = nullptr;
    }
  }

  if (current_player_ != nullptr) {
    output["current_player"] = std::move(current_player_->Serialize());
  }

  output["game_on"] = game_on_;

  output["game_mode"] = game_mode_;

  output["id"] = game_id_.has_value() ? *game_id_ : 0;

  return output;
}

std::optional<Game> Game::InitGameFromJson(const crow::json::rvalue &json) {
  Game game;

  std::unordered_map<std::string, std::shared_ptr<Player>> all_players;

  try {
    game.game_id_ = json["id"].i();
    game.game_name_ = static_cast<std::string>(json["name"]);

    for (const auto &player_json : json["players_"]) {
      auto optional_player = Player::FromJson(player_json);

      if (optional_player.has_value()) {
        auto player = std::make_shared<Player>(*optional_player);
        all_players.insert_or_assign(uuidToString(player->GetUuid()), player);
        game.players_.push_back(player);
      } else {
        game.players_.push_back(nullptr);
      }
    }

    game.p_board_ = nullptr;
    try {
      auto board = Board::FromJson(json["board"], all_players);
      if (board.has_value()) {
        game.p_board_ = std::make_unique<Board>(*board);
      }
    } catch (...) {}

    try {
      auto admin = Player::FromJson(json["admin"]);
      if (!admin.has_value()) {
        return {};
      }
      game.admin_player_ = all_players[uuidToString(admin->GetUuid())];
    } catch (const std::runtime_error &err) {
      game.admin_player_ = nullptr;
    }

    auto current_player = Player::FromJson(json["current_player"]);
    if (current_player.has_value()) {
      game.current_player_ = all_players[uuidToString(current_player->GetUuid())];
    } else {
      game.current_player_ = nullptr;
    }

    game.game_on_ = json["game_on"].b();
    game.game_mode_ = static_cast<GameMode>(json["game_mode"].i());
  } catch (...) {
    return {};
  }
  return game;
}

const vector<std::shared_ptr<Player>> &Game::GetPlayers() const {
  return players_;
}

void Game::SetAdminPlayer(const shared_ptr<Player> &admin_player) {
  admin_player_ = admin_player;
}
