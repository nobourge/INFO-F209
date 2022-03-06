#include <iostream>
#include <memory>

#include "Game.h"

using namespace std;

Game::Game() {}

Game::Game(std::vector<std::pair<Position, int>> playersPair,
           int currentPlayerIndex, std::vector<Position> walls) {

  // if (players.size>=2) We need at least 2 players to begin the game.
  int direction = 0;

  // not giving the pointer in paramater but making them here due to a previous
  // memory leak
  for (auto pair : playersPair) {
    players.push_back(std::make_shared<Player>(
        pair.first, static_cast<DIRECTION>(direction), pair.second));
    direction++;
  }

  currentPlayer = players[0];

  gameOn = true;
  board = new Board(players, walls);

  // cout<<board->GetBoardString()<<std::endl;
  // code for local testing on terminal
  // std::vector<std::string> test{"M->F", "M->F", "M->F", "M->F->L",
  // "W->a1->a2->S", "W->a2->a3->S"}; for (std::string move : test){
  //   PlayMove(move);
  //   cout<<board->GetBoardString()<<std::endl;
  // }
  // end of testing code
}

Game::Game(std::string gameName, object_id_t board_id, int nrOfPlayers)
    : gameName(gameName) {

  players.push_back(std::make_shared<Player>(Position{4, 8}, NORTH));
  players.push_back(std::make_shared<Player>(Position{4, 0}, SOUTH));

  if (nrOfPlayers > 2) {
    players.push_back(std::make_shared<Player>(Position{8, 4}, WEST));
    players.push_back(std::make_shared<Player>(Position{0, 4}, EAST));
  }

  gameOn = true;
  currentPlayer = players[0];
  board = new Board(players, {});
}

// Game() // ia game constructor
// if(gameMode==IA){
//   //If IA is on then we will have 1 Player vs 1 IA
//   players.push_back(make_shared<Ia>(Position{4,0},SOUTH));
// }

// Game()  // randomwall game constructor

Game Game::StartNewGame(std::string gameName, int nrOfPlayers,
                        object_id_t board_id) {
  return Game(gameName, board_id, nrOfPlayers);
}

std::optional<Game> Game::InitFromDB(object_id_t game_id) {
  std::string statement = "SELECT * FROM BOARD WHERE BOARD.ID=(SELECT "
                          "GAMES.BOARD_ID FROM GAMES WHERE GAMES.ID=" +
                          std::to_string(game_id) + ")";

  std::vector<std::vector<std::string>> records =
      DataBase::GetInstance()->GetSelect(statement);

  std::cout << records.size() << std::endl;

  if (records.empty()) {
    std::string error = "initialization error";
    // don't know what to do next here
    return {};
  }
  std::vector<std::string> record = records[0];

  if (std::stoi(record[1]) > 2) {
    return Game{{std::pair<Position, int>(
                     Board::GetPositionFromPositionSerialization(record[3]),
                     std::stoi(record[4])),
                 std::pair<Position, int>(
                     Board::GetPositionFromPositionSerialization(record[5]),
                     std::stoi(record[6])),
                 std::pair<Position, int>(
                     Board::GetPositionFromPositionSerialization(record[7]),
                     std::stoi(record[8])),
                 std::pair<Position, int>(
                     Board::GetPositionFromPositionSerialization(record[9]),
                     std::stoi(record[10]))},
                std::stoi(record[11]),
                Board::GetWallFromWallSerialization(record[2])};
  } else {
    return Game{{std::pair<Position, int>(
                     Board::GetPositionFromPositionSerialization(record[3]),
                     std::stoi(record[4])),
                 std::pair<Position, int>(
                     Board::GetPositionFromPositionSerialization(record[5]),
                     std::stoi(record[6]))},
                std::stoi(record[11]),
                Board::GetWallFromWallSerialization(record[2])};
  }
}

///
void Game::StartTheGame() {}

///

void Game::SwitchCurrentPlayer() {
  // First we check if the current player has won before we change the player at
  // the end of the turn
  if (hasCurrentPlayerWon()) {
    calculateRanking();
    endGame();
  }

  // system("clear"); //clears the terminal.

  if (gameMode == IA) {
    if (IaPlayer) {
      currentPlayer = players[0];
      IaPlayer = false;
    } else {
      currentPlayer = players[1];
      IaPlayer = true;
      playIaMove();
    }
  } else if (gameMode == RandomWall) {
    board->RandomWallPlacement();
  }

  // currentPlayer=next player from the vector
  cout << endl;
  cout << board->GetBoardString() << std::endl;
  cout << endl;
}

///

void Game::calculateRanking() {
  // The player who won is going to get 100 points bonus.
  currentPlayer->increaseScore(100);

  vector<int> scores;
  for (auto x : players) {
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

  // for(auto x:players){
  //   db.UpdateUser(x->getScore(), 1);
  // }
}

void Game::playIaMove() {
  bool on = false;
  string choose[2] = {"Movement", "Wall"};
  string choice = choose[rand() % 2];
  if (choice == "Movement") {
    while (!on) {
      Position coup = currentPlayer->playIAMove();
      cout << coup.row << " " << coup.col << " move" << endl;
      if (board->IsMovePossible(currentPlayer->getPlayerPos(), coup)) {
        board->Movement(currentPlayer->getPlayerPos(), coup);
        currentPlayer->setPlayerPosition(coup);
        on = true;
      } else {
        coup = currentPlayer->playIAMove(false);
        if (board->IsMovePossible(currentPlayer->getPlayerPos(), coup)) {
          board->Movement(currentPlayer->getPlayerPos(), coup);
          currentPlayer->setPlayerPosition(coup);
          on = true;
        }
      }
    }

  } else {
    // If IA places the wall then we will simply use the method from our first
    // gameMode;
    board->RandomWallPlacement();
  }
  SwitchCurrentPlayer();
}

///
/// \return
bool Game::hasCurrentPlayerWon() {
  // At the end of turn we check if the currentPlayer has won the game.
  return currentPlayer->hasWon();
}

///

void Game::joinGame() {
  // if (players.size<4) Then the player can connect to the game.
}

///
/// \return
int Game::getScore() {
  // The score for each player when the game is finished
  return 0;
}

///

void Game::endGame() {
  // Server stuff
  board->SaveToDB();
  gameOn = false;
}

///
/// \return
bool Game::gameOnGoing() {
  PlayMove("M->F");
  return gameOn;
}

void Game::PlayMove(std::string move) {
  std::string first_input = move.substr(0, move.find("->"));
  move.erase(0, move.find("->") + 2);
  std::string second_input = move.substr(0, move.find("->"));
  move.erase(0, move.find("->") + 2);

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
      std::cout << second_input[0] << " is an invalid direction" << std::endl;
      return;
    }

    Position playerMove = currentPlayer->playMove(direction);
    if (move.empty()) {
      if (board->IsMovePossible(currentPlayer->getPlayerPos(), playerMove)) {
        board->Movement(currentPlayer->getPlayerPos(), playerMove);
        currentPlayer->setPlayerPosition(playerMove);
        currentPlayer->increaseScore();
        SwitchCurrentPlayer();
      }
    } else if (second_input.size() == 1 &&
               !board->GetWallBetween(
                   board->GetCellAtPosition(currentPlayer->getPlayerPos()),
                   direction) &&
               board->GetCellAtPosition(playerMove).isPawn()) {

      std::string third_input = move;

      DIRECTION second_direction;
      std::cout << "is hop" << std::endl;

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
        std::cout << third_input[0] << " is an invalid direction" << std::endl;
        return;
      }

      std::vector<DIRECTION> possible_hops =
          board->PossiblePawnHops(playerMove, direction);

      if (!possible_hops.empty()) {
        if (std::find(possible_hops.begin(), possible_hops.end(),
                      second_direction) != possible_hops.end()) {
          board->Movement(currentPlayer->getPlayerPos(),
                          playerMove + second_direction);
          currentPlayer->setPlayerPosition(playerMove + second_direction);
          currentPlayer->increaseScore();
          SwitchCurrentPlayer();
        } else
          std::cout << "wrong hop direction" << std::endl;
      } else {
        std::cout << "impossible to hop over" << std::endl;
        return;
      }
    }

  } else if (first_input == "W") {
    std::cout << "is placing a wall" << std::endl;
    if (currentPlayer->GetNrOfWalls() <= 0) {
      cout << "out of walls" << endl;
      return;
    }
    std::string third_input = move.substr(0, move.find("->"));
    move.erase(0, move.find("->") + 2);
    std::string fourth_input = move;
    move.erase(0, 1);

    if (!move.empty())
      return;

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
      return;
    }

    pair<Position, Position> wall{Translator::Get().translateMove(second_input),
                                  Translator::Get().translateMove(third_input)};

    // Check is the placement is possible with isWallPossible();
    if (board->IsWallPossible(wall.first, wall.second, wallDirection)) {
      board->PlaceWall(wall.first, wall.second, wallDirection);
      currentPlayer->increaseScore();
      currentPlayer->DecNrOfWalls();
      SwitchCurrentPlayer();
    }

  } else {
    std::cout << "invalid input" << std::endl;
  }
}

///
/// \return
std::shared_ptr<Player> Game::getCurrentPlayer() { return currentPlayer; }

crow::json::wvalue Game::GetGameJson() {
  crow::json::wvalue output;
  output["name"] = gameName;

  if (board != nullptr) {
    output["board"] = board->Serialize();
  }

  if (admin_player != nullptr) {
    output["admin"] = admin_player->Serialize();
  }

  for (int i = 0; i < players.size(); i++) {
    if (players.at(i) != nullptr) {
      output["players"][i] = players.at(i)->Serialize();
    } else {
      output["players"][i] = nullptr;
    }
  }

  if (currentPlayer != nullptr) {
    output["current_player"] = currentPlayer->Serialize();
  }

  output["game_on"] = gameOn;

  output["game_mode"] = gameMode;

  return output;
}

void Game::SaveToDB(std::string game_name) {
  //  DataBase::GetInstance()->
}

std::optional<Game> Game::StartGameFromJson(const crow::json::rvalue &json) {
  Game game;

  try {
    game.gameName = static_cast<std::string>(json["name"]);

    try {
      auto board = json["board"];
    } catch (const std::runtime_error &err) {
      game.board = nullptr;
    }

    try {
      auto admin = Player::FromJson(json["admin"]);
      if (!admin.has_value()) {
        return {};
      }

      game.admin_player = std::make_shared<Player>(*admin);
    } catch (const std::runtime_error &err) {
      game.admin_player = nullptr;
    }

    for (int i = 0; i < json["players"].size(); i++) {
      auto player = Player::FromJson(json["players"][i]);

      if (player.has_value()) {
        game.players.push_back(std::make_shared<Player>(*player));
      } else {
        game.players.push_back(nullptr);
      }
    }

    auto current_player = Player::FromJson(json["current_player"]);
    if (current_player.has_value()) {
      game.currentPlayer = std::make_shared<Player>(*current_player);
    } else {
      game.currentPlayer = nullptr;
    }

    game.gameOn = json["game_on"].b();
    game.gameMode = static_cast<GameMode>(json["game_mode"].i());
  } catch (...) {
    return {};
  }
  return game;
}
