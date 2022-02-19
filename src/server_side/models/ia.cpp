#include"ia.h"


Ia::Ia(Position IAPos,DIRECTION dr):IAPos(IAPos),dr(dr){

}

Position Ia::playIAMove(bool forward){
    Position newPos;
    if(forward){
        newPos=Player::calculateDirection('F',IAPos,SOUTH);
    }else{
        int t=rand()%2;
        if(t==0){
            newPos=Player::calculateDirection('R',IAPos,SOUTH);
        }else{
            newPos=Player::calculateDirection('L',IAPos,SOUTH);
        }
    }

    return newPos;
}

void Ia::setPlayerPosition(Position newIAPos){
    IAPos=newIAPos;
}

Position Ia::getPlayerPos(){
    return IAPos;
}

bool Ia::hasWon(){
    bool won=false;
    if(IAPos.row==8){
            cout<<"IA Won"<<endl;
            won=true;
        }
    return won;
}

