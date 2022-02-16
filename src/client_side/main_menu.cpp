#include "main_menu.hpp"

std::vector <bool> MainMenu::getButtonState() const{
    return buttons;
}

void MainMenu::ReceiveMessage(std::string message){
    if (message == "259"){
        current_index-=1;
    }else if (message == "258"){
        current_index+=1;
    }
    buttons = {false, false, false, false, false};
    if(current_index<0)current_index=0;
    if(current_index>buttons.size()-1)current_index=buttons.size()-1;
    buttons[current_index]=true;
}