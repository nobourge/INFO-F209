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
  void settoSelect(std::vector<bool> toselect);
};



class LoginView : public MenuView{
    std::vector<bool> toSelect;
    std::vector<std::string> words = {"Pseudo", "Password" , "Confirm", "Quit"};
    std::vector<std::string> champ = {"", "", "", ""};
    const char* name = "Login Menu";
public:
  LoginView(std::vector<bool> toselect);
  void Display(WINDOW* menu) const override;
  void settoSelect(std::vector<bool> toselect);
  void setchamp(std::string newstr,int index);
};

class HelpView : public MenuView{
    std::vector<std::string> words = {"Quit"};
    const char* name = "Help";
public:
  void Display(WINDOW* menu) const override;
  void settoSelect(std::vector<bool> toselect){NULL;}
};

class StartScreenView : public MenuView{
    std::vector<std::string> words = {"Login", "Sign up", "Exit"};
    const char* name = "Quoridor";
    std::vector<bool> toSelect;
  public:
    StartScreenView(std::vector<bool> toselect);
    void Display(WINDOW* menu) const override;
    void settoSelect(std::vector<bool> toselect);
};

class TypeOfGameSelectView : public MenuView{
  std::vector<std::string> words = {"Matchmaking Online", "Matchmaking with friends", "Quit"};
  const char* name = "Online";
  std::vector<bool> toSelect;
public:
  TypeOfGameSelectView(std::vector<bool> toselect);
  void Display(WINDOW* menu) const;
  void settoSelect(std::vector<bool> toselect);
};

class SignUpView : public MenuView{
  std::vector<bool> toSelect;
  std::vector<std::string> words = {"Insert a new pseudo", "Password" , "Confirm password","Confirm", "Quit"};
  std::vector<std::string> champ = {"", "", "", "", ""};
  const char* name = "Sign up";
public:
  SignUpView(std::vector<bool> toselect);
  void Display(WINDOW* menu) const override;
  void settoSelect(std::vector<bool> toselect);
  void setchamp(std::string newstr,int index);
};