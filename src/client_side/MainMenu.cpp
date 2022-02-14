#include "MainMenu.hpp"



vector <bool> MainMenu::getButtonState() const{
    return buttons;
}

void MainMenu::ReceiveMessage(string message){
    if (message == "Z"){
        current_index-=1;
    }else if (message == "S"){
        current_index+=1;
    }
    buttons = {false, false, false, false, false};
    buttons[current_index]=true;
}