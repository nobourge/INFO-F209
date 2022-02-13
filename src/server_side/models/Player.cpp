#include<iostream>
#include"Player.h"
#include"position.h"

using namespace std;

Player::Player(Position playerPos,DIRECTION dr):playerPos(playerPos),dr(dr){
  
}

bool Player::isTurnOver(){
    return true;
}

//TODO
bool Player::hasWon(){
    if(dr==NORTH){
        if(playerPos.row==0){
            cout<<"Game Won"<<endl;
            return true;
        }
    }else if(dr==SOUTH){
        if(playerPos.row==8){
            cout<<"Game Won"<<endl;
            return true;
        }
    }else if(dr==EAST){
        if(playerPos.col==8){
            cout<<"Game Won"<<endl;
            return true;
        }
    }else{
        if(playerPos.col==0){
            cout<<"Game Won"<<endl;
            return true;
        }
    }

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
            cout<<"To move your player forward write F , backwards B , right side R and left side L"<<endl;
            cin>>enter;
            //TODO Forward movement is different for each player normally
            if(enter=='F'){
                    return calculateDirection('F');
                    
            }else if(enter=='R'){
                    return calculateDirection('R');
                
            }else if(enter=='L'){
                    return calculateDirection('L');
            }
            else if(enter=='B'){
                    return calculateDirection('B');
            } 
            else{
                cout<<"Coup Invalid"<<endl;
            }
            
        }else{
            cout<<"Coup Invalid"<<endl;
        }
        
    }
    
    isTurnOver();
}

Position Player::calculateDirection(char c){
    Position coup;
    if(c =='F'){
        if(dr==NORTH){
            coup=Position{playerPos.col,playerPos.row-1};
        }
        else if(dr==EAST){
            coup=Position{playerPos.col+1,playerPos.row};
        }
        else if(dr==SOUTH){
            coup=Position{playerPos.col,playerPos.row+1};
        }
        else{
            coup=Position{playerPos.col-1,playerPos.row};
        }
    }
    else if(c =='R'){
        if(dr==NORTH){
            coup=Position{playerPos.col+1,playerPos.row};
        }
        else if(dr==EAST){
            coup=Position{playerPos.col,playerPos.row+1};
        }
        else if(dr==SOUTH){
            coup=Position{playerPos.col-1,playerPos.row};
        }
        else{
            coup=Position{playerPos.col,playerPos.row-1};
        }
    }else if(c=='L'){
        if(dr==NORTH){
            coup=Position{playerPos.col-1,playerPos.row};
        }
        else if(dr==EAST){
            coup=Position{playerPos.col,playerPos.row-1};
        }
        else if(dr==SOUTH){
            coup=Position{playerPos.col+1,playerPos.row};
        }
        else{
            coup=Position{playerPos.col,playerPos.row+1};
        }
    }else{
        if(dr==NORTH){
            coup=Position{playerPos.col,playerPos.row+1};
        }
        else if(dr==EAST){
            coup=Position{playerPos.col-1,playerPos.row};
        }
        else if(dr==SOUTH){
            coup=Position{playerPos.col,playerPos.row-1};
        }
        else{
            coup=Position{playerPos.col+1,playerPos.row};
        }
    }
    return coup;
}

void Player::setPlayerPosition(Position newPos){
    playerPos=newPos;
}

Position Player::getPlayerPos(){
    return playerPos;
}