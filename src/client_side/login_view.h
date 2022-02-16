#include "view/MenuView.h"
#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>


class LoginView : public MenuView{
    std::vector<bool> toSelect;
    std::vector<std::string> words = {"Pseudo", "Password"};
    const char* name = "Login Menu";
public:
    LoginView(std::vector<bool> toselect);
    void Display(WINDOW* menu) const;
    void OpenMenu(){NULL;};
    void settoSelect(std::vector<bool> toselect);
};