#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "MenuView.h"


class MainMenuView : public MenuView{
    std::vector<bool> toSelect ;
    std::vector<std::string> words = {"Play", "Friend List" , "Ranking", "Help", "Quit"};
    const char* name = "Main Menu";
public:
  MainMenuView(std::vector<bool> toselect);
  void Display(WINDOW* menu) const;
  void OpenMenu(){NULL;};
  void settoSelect(std::vector<bool> toselect);
};


class LoginView : public MenuView{
    std::vector<bool> toSelect;
    std::vector<std::string> words = {"Pseudo", "Password" , "Confirm"};
    std::vector<std::string> champ = {"", "", ""};
    const char* name = "Login Menu";
public:
  LoginView(std::vector<bool> toselect);
  void Display(WINDOW* menu) const override;
  void OpenMenu(){NULL;};
  void settoSelect(std::vector<bool> toselect);
  void setchamp(std::string newstr,int index);
};

class HelpView : public MenuView{
    std::vector<bool> toSelect;
    std::vector<std::string> words = {"Quit"};
    const char* name = "Help";
public:
    void OpenMenu(){NULL;};
    void Display(WINDOW* menu) const override;
};