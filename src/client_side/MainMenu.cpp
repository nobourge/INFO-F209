#include "MainMenu.hpp"



vector <bool> MainMenu::getButtonState() const{
    return buttons;
}

void MainMenu::ReceiveMessage(string message){
    if (message == "122"){
        current_index-=1;
    }else if (message == "115"){
        current_index+=1;
    }
    buttons = {false, false, false, false, false};
    if(current_index<0)current_index=0;
    if(current_index>buttons.size()-1)current_index=buttons.size()-1;
    buttons[current_index]=true;
}