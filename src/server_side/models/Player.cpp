#include<iostream>
#include"Player.h"
#include"position.h"

using namespace std;

Player::Player(Position playerPos,Position finishLine,Board* board):playerPos(playerPos),finishLine(finishLine),board(board){}

bool Player::isTurnOver(){
    return true;
}

//TODO
bool Player::hasWon(){
    return false;
}

void Player::playCoup(){

    int x,y;

    bool coupValid=false;

    while(!coupValid){
        char enter;
        cout<<"Do you want to move your player or place a wall?"<<endl<<"To make your choice please write W (place wall) or M (move player)"<<endl;
        cin>>enter;
        if(enter=='W'){
            //TODO
            cout<<"You have chosen to place a wall"<<endl;
            cout<<"Please chose were to place the wall and the direction (N,S,E,W)"<<endl;

            nbWalls--;
            coupValid=true;
        }else if(enter=='M'){
            cout<<"You have chosen to move your player"<<endl;
            cout<<"To move your player forward write F , right side R and left side L"<<endl;
            cin>>enter;
            //TODO
            if(enter=='F'){
                if(board->isMovePossible(playerPos,Position{playerPos.row-1,playerPos.col})){
                    
                    setPlayerPosition(Position{playerPos.row-1,playerPos.col});
                    cout<<playerPos.col<<endl;
                    cout<<playerPos.row<<endl;
                   
                    coupValid=true;
                }
            }else if(enter=='R'){
                if(board->isMovePossible(playerPos,Position{playerPos.row,playerPos.col+1})){
                    setPlayerPosition(Position{playerPos.row,playerPos.col+1});
                    coupValid=true;
                }
            }else if(enter=='L'){
                  if(board->isMovePossible(playerPos,Position{playerPos.row,playerPos.col-1})){
                    setPlayerPosition(Position{playerPos.row,playerPos.col});
                    coupValid=true;
                  }
            }else{
                cout<<"Coup Invalid"<<endl;
            }
            
        }else{
            cout<<"Coup Invalid"<<endl;
        }
        
    }
    
    isTurnOver();
}

void Player::setPlayerPosition(Position newPos){
    playerPos=newPos;
}

Position Player::getPlayerPos(){
    return playerPos;
}