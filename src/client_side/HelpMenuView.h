#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "MenuView.h"

class HelpMenuView : public MenuView{
private:
    const char* name = "Help Menu";
public:
    void DisplayHelp() const;
    void OpenMenu(){NULL;}
};