#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "MainMenuView.h"


void MainMenuView::Display(WINDOW* menu) const{
        //system("clear");
        for (unsigned long int i = 0; i<words.size(); i++){
          wrefresh(menu);
            if (toSelect[i]){
              mvwprintw(menu,i, 0, "%s",">");
            }
            mvwprintw(menu,i, 1, "%s",words[i].c_str());

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
