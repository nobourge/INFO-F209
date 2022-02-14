
#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "MenuView.h"

class MainMenuView : public MenuView{
private:
    std::vector<bool> toSelect ;//= {false, false, true, false, false};
    std::vector<std::string> words = {"Play", "Friend List" , "Ranking", "Help", "Quit"};
    const char* name = "Main Menu";
    const int decalage = 4;

public:
  MainMenuView( std::vector<bool> toselect);
    void Display() const;
    void OpenMenu(){NULL;};
    void settoSelect(std::vector<bool> toselect);
};
