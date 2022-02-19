#include <iostream>
#include <vector>
//#include "enum_factory.h"
#include "abstract_controller.h"
class MainMenu{
    std::vector<bool> buttons = {true, false, false, false, false};
    int current_index = 0;
public:
    std::vector <bool> getButtonState() const ;
    void ReceiveMessage(std::string message);
    EnumFactory::SelectionableMenu ReceiveEnterMessage();
};

class Login{
    std::vector <std::string> data={"",""};
  std::vector<bool> buttons = {true, false, false, false, false};
  int current_index = 0;
public:
    std::vector <bool> getButtonState() const ;
    void ReceiveMessage(std::string message);
    EnumFactory::SelectionableMenu ReceiveEnterMessage();
    std::vector <std::string> getData() const ;
    void SetUsername(std::string username);
    void setPassword(std::string password);
};
class Help{
 public:
  EnumFactory::SelectionableMenu ReceiveEnterMessage();
};
class StartScreen{
  std::vector<bool> buttons = {true, false, false};
  int current_index = 0;
 public:
  std::vector <bool> getButtonState() const ;
  void ReceiveMessage(std::string message);
  EnumFactory::SelectionableMenu ReceiveEnterMessage();
};

class TypeOfGameSelect{
  std::vector<bool> buttons = {true, false, false};
  int current_index = 0;
 public:
  std::vector <bool> getButtonState() const ;
  void ReceiveMessage(std::string message);
  EnumFactory::SelectionableMenu ReceiveEnterMessage();
};