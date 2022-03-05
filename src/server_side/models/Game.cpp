#include <iostream>
#include <memory>

#include "Game.h"

using namespace std;


Game::Game() {}

Game::Game(std::vector<std::shared_ptr<Player>> players, int currentPlayerIndex,
           std::vector<Position> walls):
           players{players}, currentPlayer{players[currentPlayerIndex]} {

  // if (players.size>=2) We need at least 2 players to begin the game.
  gameOn = true;
  board = new Board (players, walls);
  cout<<board->GetBoardString()<<std::endl;
}

// Game() // ia game constructor
// if(gameMode==IA){
  //   //If IA is on then we will have 1 Player vs 1 IA
  //   players.push_back(make_shared<Ia>(Position{4,0},SOUTH));
  // }


// Game()  // randomwall game constructor


std::optional<Game> Game::InitFromDB(object_id_t game_id) {
  std::string statement = "SELECT * FROM BOARD WHERE BOARD.ID=(SELECT GAMES.BOARD_ID FROM GAMES WHERE GAMES.ID="+std::to_string(game_id)+")";
  std::cout<<statement<<std::endl;

  std::vector<std::vector<std::string>> records = DataBase::GetInstance()->
    GetSelect(statement);

  std::cout<<records.size()<<std::endl;

  if (records.empty()) {
    std::string error = "initialization error";
    // don't know what to do next here
    return {};
  }
  std::vector<std::string> record = records[0];



  if (std::stoi(record[1]) > 2){
    return Game{ {std::make_shared<Player>(Board::GetPositionFromPositionSerialization(record[3]), NORTH, std::stoi(record[4])),
                 std::make_shared<Player>(Board::GetPositionFromPositionSerialization(record[5]), SOUTH, std::stoi(record[6])),
                 std::make_shared<Player>(Board::GetPositionFromPositionSerialization(record[7]), SOUTH, std::stoi(record[8])),
                 std::make_shared<Player>(Board::GetPositionFromPositionSerialization(record[9]), SOUTH, std::stoi(record[10]))},
                 std::stoi(record[11]), Board::GetWallFromWallSerialization(record[2])};
  }else{
    return Game{{std::make_shared<Player>(Board::GetPositionFromPositionSerialization(record[3]), NORTH, std::stoi(record[4])),
                 std::make_shared<Player>(Board::GetPositionFromPositionSerialization(record[5]), SOUTH, std::stoi(record[6]))},
                 std::stoi(record[11]), Board::GetWallFromWallSerialization(record[2])};
  }
}

///
void Game::StartTheGame() {

}

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
  playCoup();
  return gameOn;
}

///

void Game::playCoup() {
  bool on = false;

  while (!on) {
    Input input;
    cout << "Do you want to move your player or place a wall?" << endl
         << "To make your choice please write W (place wall) or M (move player)"
         << endl;
    char enter = input.getInput();
    if (enter == 'W') {
      if (currentPlayer->GetNrOfWalls() <= 0) {
        cout << "out of walls" << endl;
        break;
      }

      string placement = input.getInputWall();
      DIRECTION direct;
      pair<Position, Position> wall = currentPlayer->placeWall(placement);
      char direction = placement[8];
      cout << wall.first.col << " " << wall.first.row << endl;
      cout << wall.second.col << " " << wall.second.row << endl;
      cout << direction << endl;
      switch (direction) {
      case 'N':
        direct = NORTH;
        break;
      case 'S':
        direct = SOUTH;
        break;
      case 'E':
        direct = EAST;
        break;
      case 'W':
        direct = WEST;
        break;
      }

      // Check is the placement is possible with isWallPossible();
      if (board->IsWallPossible(wall.first, wall.second, direct)) {
        board->PlaceWall(wall.first, wall.second, direct);
        currentPlayer->increaseScore();
        on = true;
        currentPlayer->DecNrOfWalls();
      }

        }else if(enter=='M'){
                DIRECTION direction=input.getInputMovement();
                Position coup=currentPlayer->playMove(direction);
                if(board->IsMovePossible(currentPlayer->getPlayerPos(),coup)){
                    // board->Movement(currentPlayer->getPlayerPos(),false);
                    board->Movement(currentPlayer->getPlayerPos(),coup);
                    currentPlayer->setPlayerPosition(coup);
                    // board->Movement(coup,true);
                    currentPlayer->increaseScore();
                    on=true;
                }
                else if(!board->GetWallBetween(board->GetCellAtPosition(currentPlayer->getPlayerPos()), direction)
                        && board->GetCellAtPosition(coup).isPawn()){
                    //it just works
                    std::vector<DIRECTION> possible_hops = board->PossiblePawnHops(coup, direction);
                    if (possible_hops.size() == 1) {
                        board->Movement(currentPlayer->getPlayerPos(), coup+possible_hops[0]);
                        currentPlayer->setPlayerPosition(coup+possible_hops[0]);
                        currentPlayer->increaseScore();
                        on=true;
                    }else if (! possible_hops.empty()) {
                        DIRECTION second_direction = input.getInputMovement();
                        if (std::find(possible_hops.begin(), possible_hops.end(), second_direction) != possible_hops.end()){
                            board->Movement(currentPlayer->getPlayerPos(), coup+second_direction);
                            currentPlayer->setPlayerPosition(coup+second_direction);
                            currentPlayer->increaseScore();
                            on=true;
                        }
                    }

                  }

    } else {
      cout << "Move invalid" << endl;
    }
  }

  SwitchCurrentPlayer();
}

///
/// \return
std::shared_ptr<Player> Game::getCurrentPlayer() { return currentPlayer; }

crow::json::wvalue Game::GetGameJson() {
  crow::json::wvalue game_json;
  int wall_index = 0;
  string item;

  for (int row=0; row<kBoardSize*2 -1; row++ ){
      for (int col=0; col<kBoardSize*2 -1; col++ ){
        if (board->GetWalls()[row][col]){
          item = std::to_string(col)+","+std::to_string(row);
          game_json["walls"][wall_index] = item;
          wall_index++;
        }
      }
  }

  // should change in the future as there is a lot of code repetition
  if (players.size() > 2){
    crow::json::wvalue player;

    player["position"] = Board::GetPositionSerialization(players[0]->getPlayerPos());
    player["walls_left"] = players[0]->GetNrOfWalls();
    game_json["player1"] = std::move(player);

    player["position"] = Board::GetPositionSerialization(players[1]->getPlayerPos());
    player["walls_left"] = players[1]->GetNrOfWalls();
    game_json["player2"] = std::move(player);

    player["position"] = Board::GetPositionSerialization(players[2]->getPlayerPos());
    player["walls_left"] = players[2]->GetNrOfWalls();
    game_json["player3"] = std::move(player);

    player["position"] = Board::GetPositionSerialization(players[3]->getPlayerPos());
    player["walls_left"] = players[3]->GetNrOfWalls();
    game_json["player4"] = std::move(player);
  }else{
    crow::json::wvalue player;

    player["position"] = Board::GetPositionSerialization(players[0]->getPlayerPos());
    player["walls_left"] = players[0]->GetNrOfWalls();
    game_json["player1"] = std::move(player);

    player["position"] = Board::GetPositionSerialization(players[1]->getPlayerPos());
    player["walls_left"] = players[1]->GetNrOfWalls();
    game_json["player2"] = std::move(player);
  }

  return  game_json;

}
