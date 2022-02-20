#include"input.h"

using namespace std;

///
/// \return
char Input::getInput(){
    char movement;
    cin>>movement;
    return movement;
}

///
/// \return
DIRECTION Input::getInputMovement(){
    bool on=false;
    DIRECTION direction;
    while(!on){
        char enter;        
        cout<<"You have chosen to move your player"<<endl;
        cout<<"To move your player forward write F , backwards B , right side R and left side L"<<endl;
        cin>>enter;
      
        if(enter=='F'){
                direction=NORTH;
                on=true;
                        
        }else if(enter=='R'){
                    direction=EAST;
                    on=true;
                    
        }else if(enter=='L'){
                    direction=WEST;
                    on=true;
        }
        else if(enter=='B'){
                     direction=SOUTH;
                     on=true;
        } 
        else{
            cout<<"Coup Invalid"<<endl;
            }   
        }
    return direction;
    
}   

///
/// \return
string Input::getInputWall(){
     
    cout<<"You have chosen to place a wall"<<endl;
    cout<<"Please chose were to place the wall example on case a1->a2->N"<<endl;
    string placement;
    cin>>placement;
    return placement;
     
}
