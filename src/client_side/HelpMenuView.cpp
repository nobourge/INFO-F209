#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "HelpMenuView.h"


void HelpMenuView::DisplayHelp() const{
        WINDOW *boite;
        int taille= strlen(name);
        initscr();
        while(1) {
            clear();
            attron(A_STANDOUT);
            mvprintw(0, (COLS / 2) - (taille / 2), name);
            attroff(A_STANDOUT);
            mvprintw(decalage,0, "Quoridor is played on a game board of 81 square spaces (9x9). Each player is represented by a pawn which begins at the center space of one edge of the board (in a two-player game, the pawns begin opposite each other). The objective is to be the first player to move their pawn to any space on the opposite side of the game board from which it begins. ");
            refresh();

            int catchInput = getch();
            if(catchInput != 410)
                break;
        }
        
        endwin();   
        free(boite);

}

int main(){
    HelpMenuView help;
    help.DisplayHelp();
}