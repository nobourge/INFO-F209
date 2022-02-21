#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "abstract_menu_view.h"
#include "../view_elements/button.h"



class HomeMenuView : public AbstractMenuView {
 public:
  static constexpr char menu_name_[] = "Home";
  HomeMenuView();
  const ButtonHandlersDict &GetSubmenus() override;
 private:
  ButtonHandlersDict submenus_ =
      {{"Play", {}}, {"Friend List", {}}, {"Ranking", {}}, {"Help", {}}, {"Quit", {}}};
};



//class LoginMenuView : public AbstractMenuView{
//    std::vector<bool> toSelect;
//    std::vector<std::string> words = {"Pseudo", "Password" , "Confirm"};
//    std::vector<std::string> champ = {"", "", ""};
//    const char* name = "Login Menu";
//public:
//  LoginMenuView(const char *name,
//                WINDOW *window,
//                std::vector<bool> toSelect);
//  void Draw() const override;
//  void settoSelect(std::vector<bool> toselect);
//  void setchamp(std::string newstr,int index);
//};