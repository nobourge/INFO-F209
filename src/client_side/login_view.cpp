#include "login_view.h"



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
        }
};

void LoginView::settoSelect(std::vector<bool> toselect){toSelect=toselect;}
