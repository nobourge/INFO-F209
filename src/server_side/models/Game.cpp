#include<iostream>
#include<memory>

#include"Game.h"

using namespace std;


Game::Game(){

}


void Game::StartTheGame(){
    
    db.createTables();
    // if (players.size>=2) We need at least 2 players to begin the game.
    gameOn=true;
    //When player connects from the server ... TODO

    players.push_back(make_shared<Player>(Position{4,8},NORTH));
    //For now we have only 1 player
    currentPlayer=players[0];
    cout<<endl;

    if(gameMode==IA){
        //If IA is on then we will have 1 Player vs 1 IA
        players.push_back(make_shared<Ia>(Position{4,0},SOUTH));
    }
    vector<Position> walls{{0,3}};
    // vector<Position> walls{{0,3},{2,3},{4,3},{6,3},{8,3},{10,3},{12,3},{14,3},{16,3}};
    board = new Board (players, walls);
    
    //Insert the data for all the players in the db
    for(auto x:players){
        db.inserPlayer(x);
    }
    //Insert the data for the board
    db.insertBoard(players.size(),walls.size());

    cout<<board->GetBoardString()<<endl;


}

void Game::SwitchCurrentPlayer(){
    //First we check if the current player has won before we change the player at the end of the turn
    if(hasCurrentPlayerWon()){
        endGame();
    }

    system("clear"); //clears the terminal.

    if(gameMode==IA){
        if(IaPlayer){
            currentPlayer=players[0];
            IaPlayer=false;
        }else{
            currentPlayer=players[1];
            IaPlayer=true;
            playIaMove();
        }
    }else if(gameMode==RandomWall){
        board->randomWallPlacement();
    }

    //currentPlayer=next player from the vector
    cout<<currentPlayer->getPlayerPos().row<<" "<<currentPlayer->getPlayerPos().col<<endl;
    cout<<endl;
    cout<<board->GetBoardString()<<std::endl;
    cout<<endl;


}

void Game::playIaMove(){
    bool on=false;
    string choose[2]={"Movement","Wall"};
    string choice=choose[rand()%2];
    if(choice=="Movement"){
        while(!on){
            Position coup=currentPlayer->playIAMove();
            cout<<coup.row<<" "<<coup.col<<" move"<<endl;
            if(board->IsMovePossible(currentPlayer->getPlayerPos(),coup)){
                    board->Movement(currentPlayer->getPlayerPos(),coup);
                    currentPlayer->setPlayerPosition(coup);
                    on=true;
            }else{
                coup=currentPlayer->playIAMove(false);
                 if(board->IsMovePossible(currentPlayer->getPlayerPos(),coup)){
                    board->Movement(currentPlayer->getPlayerPos(),coup);
                    currentPlayer->setPlayerPosition(coup);
                    on=true;
                }
            }
        }

    }else{
        //If IA places the wall then we will simply use the method from our first gameMode;
        board->randomWallPlacement();
    }
    SwitchCurrentPlayer();
}

bool Game::hasCurrentPlayerWon(){
    //At the end of turn we check if the currentPlayer has won the game.
    return currentPlayer->hasWon();
}

void Game::joinGame(){
    //if (players.size<4) Then the player can connect to the game.

}

int Game::getScore(){
    //The score for each player when the game is finished
    return 0;
}

void Game::endGame(){
    //Server stuff
    gameOn=false;
}

bool Game::gameOnGoing(){
    playCoup();
    return gameOn;
}

void Game::playCoup(){
    bool on=false;

    while(!on){
        Input input;
        cout<<"Do you want to move your player or place a wall?"<<endl<<"To make your choice please write W (place wall) or M (move player)"<<endl;
        char enter=input.getInput();
        if(enter=='W'){
            string placement=input.getInputWall();
            DIRECTION direct;
            pair<Position,Position> wall=currentPlayer->placeWall(placement);
            char direction=placement[8];
            cout<<wall.first.col<<" "<<wall.first.row<<endl;
            cout<<wall.second.col<<" "<<wall.second.row<<endl;
            cout<<direction<<endl;
            switch (direction){
                case 'N':
                    direct=NORTH;
                    break;
                case 'S':
                    direct=SOUTH;
                    break;
                case 'E':
                    direct=EAST;
                    break;
                case 'W':
                    direct=WEST;
                    break;
            }

            //Check is the placement is possible with isWallPossible();
            board->PlaceWall(wall.first,wall.second,direct);
            on=true;

        }else if(enter=='M'){
                DIRECTION direction=input.getInputMovement();
                Position coup=currentPlayer->playMove(direction);
                if(board->IsMovePossible(currentPlayer->getPlayerPos(),coup)){
                    // board->Movement(currentPlayer->getPlayerPos(),false);
                    board->Movement(currentPlayer->getPlayerPos(),coup);
                    currentPlayer->setPlayerPosition(coup);
                    // board->Movement(coup,true);
                    on=true;
                 }

        }else{
            cout<<"Move invalid"<<endl;
        }
    }
    SwitchCurrentPlayer();

}

std::shared_ptr<Player> Game::getCurrentPlayer(){
    return currentPlayer;
}
