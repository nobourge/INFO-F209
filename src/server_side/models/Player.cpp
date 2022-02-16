#include<iostream>
#include"Player.h"
#include"position.h"

using namespace std;

Player::Player(Position playerPos,DIRECTION dr):playerPos(playerPos),dr(dr){
  
}

bool Player::isTurnOver(){
    return true;
}


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


pair<Position,Position> Player::placeWall(string placement){
    //Cut the a1->a2->N in a1 , a2 and N;
    std::string delimiter = "->";
	translator translate;
	std::string case1 = placement.substr(0, placement.find(delimiter));
	
	placement.erase(0, placement.find(delimiter) + delimiter.length());
	string case2 = placement.substr(0, placement.find(delimiter));
	

    //Translate the move a1 in Position;
    Position move1=translate.translateMove(case1);
    Position move2=translate.translateMove(case2);

    pair<Position,Position> ret={move1, move2};
    return ret;
}

Position Player::playMove(DIRECTION direction){


    if(direction==NORTH){
            return calculateDirection('F');
                    
    }else if(direction==EAST){
                    return calculateDirection('R');
                
    }else if(direction==WEST){
            return calculateDirection('L');
            }
    else if(direction==SOUTH){
                    return calculateDirection('B');
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