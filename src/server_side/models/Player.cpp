#include<iostream>
#include"Player.h"
#include"position.h"

using namespace std;

Player::Player(Position playerPos,Position finishLine):playerPos(playerPos),finishLine(finishLine){
  
}

bool Player::isTurnOver(){
    return true;
}

//TODO
bool Player::hasWon(){
    return false;
}

Position Player::playCoup(){

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
            //TODO Forward movement is different for each player normally
            if(enter=='F'){
                    return Position{playerPos.col,playerPos.row-1};
                    
            }else if(enter=='R'){
        
                    return Position{playerPos.col+1,playerPos.row};
                
            }else if(enter=='L'){
                    return Position{playerPos.col-1,playerPos.row};
                       
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