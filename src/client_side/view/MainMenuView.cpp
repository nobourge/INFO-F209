#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "MainMenuView.h"


void MainMenuView::Display() const{
        system("clear");
        for (unsigned long int i = 0; i<words.size(); i++){
            if (toSelect[i]){
                std::cout << ">";
            }
            std::cout << words[i] << std::endl;
        }
};
MainMenuView::MainMenuView(std::vector<bool> toSelect) :toSelect(toSelect){}

void MainMenuView::settoSelect(std::vector<bool> toselect) {
toSelect=toselect;
}
//
//int main(){
//    MainMenuView Menu;
//    Menu.Display();
//}
