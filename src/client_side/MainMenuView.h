#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "MenuView.h"

class MainMenuView : public MenuView{
private:
    std::vector<bool> toBright = {false, false, true, false, false};
    std::vector<const char*> words = {"Play", "Friend List" , "Ranking", "Help", "Quit"};
    const char* name = "Main Menu";
    const int decalage = 4;

public:
    void Display() const;
    void OpenMenu(){NULL;};
};
