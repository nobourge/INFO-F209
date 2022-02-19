#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "MainMenuView.h"


void MainMenuView::Display(WINDOW* menu) const{
        initscr();
        wrefresh(menu);
        wattr_on(menu, A_BOLD, 0);
        int center_y = COLS/2;
        mvwprintw(menu, 0, center_y - (strlen(name) / 2) ,name);
        wattr_off(menu, A_BOLD, 0);
        for (unsigned long int i = 0; i<words.size(); i++){
            if (toSelect[i]){
              wattr_on(menu, A_UNDERLINE, 0);
            }
            mvwprintw(menu,decalage + i*2, center_y - (strlen(words[i].c_str()) / 2) ,words[i].c_str());
            wattr_off(menu, A_UNDERLINE, 0);
        }
        

};
MainMenuView::MainMenuView(std::vector<bool> toSelect) :toSelect(toSelect){}

void MainMenuView::settoSelect(std::vector<bool> toselect) {
toSelect=toselect;
}


void LoginView::Display(WINDOW* menu) const{
  initscr();
  wrefresh(menu);
  wattr_on(menu, A_BOLD, 0);
  int center_y = COLS/2;
  mvwprintw(menu, 0, center_y - (strlen(name) / 2) ,name);
  wattr_off(menu, A_BOLD, 0);
  for (unsigned long int i = 0; i<words.size(); i++){
      if (toSelect[i]){
        wattr_on(menu, A_UNDERLINE, 0);
      }
      mvwprintw(menu,decalage + i*2, center_y - (strlen(words[i].c_str()) / 2) ,words[i].c_str());
      wattr_off(menu, A_UNDERLINE, 0);
      mvwprintw(menu,decalage + i*2, 70,champ[i].c_str());
  }
};


LoginView::LoginView(std::vector<bool> toSelect) :toSelect(toSelect){}
void LoginView::settoSelect(std::vector<bool> toselect){toSelect=toselect;}
void LoginView:: setchamp(std::string newstr,int index){champ[index]=newstr;}


void HelpView::Display(WINDOW* menu) const{
  initscr();
  wrefresh(menu);
  wattr_on(menu, A_BOLD, 0);
  int center_y = COLS/2;
  mvwprintw(menu, 0, center_y - (strlen(name) / 2) ,name);
  wattr_off(menu, A_BOLD, 0);

  mvwprintw(menu, decalage, 0, "Quoridor is played on a game board of 81 square spaces (9x9). Each player is represented by a pawn which begins at the center space of one edge of the board (in a two-player game, the pawns begin opposite each other)." );

  if (toSelect[0]){
    wattr_on(menu, A_UNDERLINE, 0);
    mvwprintw(menu, decalage + 6, center_y - (strlen(words[0].c_str()) / 2) ,words[0].c_str());
    wattr_off(menu, A_UNDERLINE, 0);
  }
}