#include<iostream>
#include<memory>

#include"Game.h"

using namespace std;


Game::Game(){

}


void Game::StartTheGame(){

    // if (players.size>=2) We need at least 2 players to begin the game.
    gameOn=true;
    //When player connects from the server ... TODO

    players.push_back(make_shared<Player>(Position{4,8},NORTH));
    //For now we have only 1 player
    currentPlayer=players[0];
    cout<<endl;

    vector<Position> walls{Position{0,1}};
    vector<Position> pawns {currentPlayer->getPlayerPos()};

    board = new Board (pawns, walls);

    cout<<board->GetBoardString()<<endl;


}

void Game::SwitchCurrentPlayer(){
    //First we check if the current player has won before we change the player at the end of the turn
    if(hasCurrentPlayerWon()){
        endGame();
    }
    //currentPlayer=next player from the vector
    cout<<currentPlayer->getPlayerPos().row<<" "<<currentPlayer->getPlayerPos().col<<endl;
    cout<<endl;
    cout<<board->GetBoardString()<<std::endl;
    cout<<endl;

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
        char enter;
        cout<<"Do you want to move your player or place a wall?"<<endl<<"To make your choice please write W (place wall) or M (move player)"<<endl;
        cin>>enter;
        if(enter=='W'){
            //TODO
            cout<<"You have chosen to place a wall"<<endl;
            cout<<"Please chose were to place the wall example on case a1->a2->N"<<endl;
            string placement;
            DIRECTION direct;
            cin>>placement;
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
                Position coup=currentPlayer->playMove();
                if(board->IsMovePossible(currentPlayer->getPlayerPos(),coup)){
                    board->Movement(currentPlayer->getPlayerPos(),false);
                    currentPlayer->setPlayerPosition(coup);
                    board->Movement(coup,true);
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
