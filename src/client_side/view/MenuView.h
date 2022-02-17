#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>

class MenuView{
public:
  virtual void OpenMenu() = 0;
  const int decalage = 4;
  const char* name;
  virtual void Display(WINDOW* menu) const=0;
  virtual void settoSelect(std::vector<bool> toselect)=0;
};