#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "MainMenuView.h"


void MainMenuView::Display() const{
    WINDOW *boite;
    int taille= strlen(name);
    initscr();
    while(1) {
        clear();    // Efface la fenêtre (donc l'ancien message)
        attron(A_STANDOUT);
        mvprintw(0, (COLS / 2) - (taille / 2), name);
        attroff(A_STANDOUT);
        for (int i = 0; i < words.size(); i++){
            if (toBright[i]){
                attron(A_UNDERLINE);
            }else{
                attroff(A_UNDERLINE);
            }
            mvprintw(decalage + i*2, (COLS / 2) - (taille / 2), words[i]);

        }
        refresh();
        if(getch() != 410)
            break;

    }
    
    endwin();   
    free(boite);
}

int main(){
    MainMenuView Menu;
    Menu.Display(); 
}