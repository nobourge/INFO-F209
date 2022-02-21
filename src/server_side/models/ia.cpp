#include"ia.h"


Ia::Ia(Position IAPos,DIRECTION dr): Player{IAPos, dr}{

}

Position Ia::playIAMove(bool forward){
    Position newPos;
    if(forward){
        newPos=Player::calculateDirection('F',getPlayerPos(),SOUTH);
    }else{
        int t=rand()%2;
        if(t==0){
            newPos=Player::calculateDirection('R',getPlayerPos(),SOUTH);
        }else{
            newPos=Player::calculateDirection('L',getPlayerPos(),SOUTH);
        }
    }

    return newPos;
}

bool Ia::hasWon(){
    bool won=false;
    if(getPlayerPos().row==8){
            cout<<"IA Won"<<endl;
            won=true;
        }
    return won;
}
