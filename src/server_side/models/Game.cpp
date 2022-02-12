#include<iostream>
#include<memory>

#include"Game.h"

using namespace std;


Game::Game(){
    
}


void Game::StartTheGame(){

    //if (players.size>=2) We need at least 2 players to begin the game.
    gameOn=true;
    //When player connects from the server ... TODO
    
    players.push_back(make_shared<Player>(Position{4,0},Position{8,8},SOUTH));
    //For now we have only 1 player
    currentPlayer=players[0];
    cout<<endl;
    vector<Position> walls{Position{0,1}};
    board=new Board({currentPlayer->getPlayerPos()}, walls);

    cout<<board->getBoardString()<<endl;
      
      
}

void Game::SwitchCurrentPlayer(){
    //First we check if the current player has won before we change the player at the end of the turn
    if(hasCurrentPlayerWon()){
        endGame();
    }
    //currentPlayer=next player from the vector
    cout<<currentPlayer->getPlayerPos().row<<" "<<currentPlayer->getPlayerPos().col<<endl;
    cout<<endl;
    cout<<board->getBoardString()<<std::endl;
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
        Position coup=currentPlayer->playCoup();
        if(board->isMovePossible(currentPlayer->getPlayerPos(),coup)){
            board->Movement(currentPlayer->getPlayerPos(),false);
            currentPlayer->setPlayerPosition(coup);
            board->Movement(coup,true);
            on=true;
         }
    }
    SwitchCurrentPlayer();
    
}

std::shared_ptr<Player> Game::getCurrentPlayer(){
    return currentPlayer;
}