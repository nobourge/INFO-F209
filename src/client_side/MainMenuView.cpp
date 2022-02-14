#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "MainMenuView.h"


void MainMenuView::Display() const{
    WINDOW *boite;
    int taille= strlen(name.c_str());
    initscr();
    while(1) {
        clear();    // Efface la fenêtre (donc l'ancien message)
        attron(A_STANDOUT);
        mvprintw(0, (COLS / 2) - (taille / 2), name.c_str());
        attroff(A_STANDOUT);
        for (int i = 0; i < words.size(); i++){
            if (toBright[i]){
                attron(A_UNDERLINE);
            }else{
                attroff(A_UNDERLINE);
            }
            mvprintw(decalage + i*2, (COLS / 2) - (taille / 2), words[i].c_str());

        }
        refresh();
        if(getch() != 410)
            break;

    }
    
    endwin();
}
