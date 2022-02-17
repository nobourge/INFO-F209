#include <iostream>
#include <vector>

class MainMenu{
    std::vector<bool> buttons = {false, false, true, false, false};
    int current_index = 2;
public:
    std::vector <bool> getButtonState() const ;
    void ReceiveMessage(std::string message);
};

class Login{
    std::vector <std::string> data={"",""};
  std::vector<bool> buttons = {false, false, true, false, false};
  int current_index = 2;
public:
    std::vector <bool> getButtonState() const ;
    void ReceiveMessage(std::string message);
    int ReceiveEnterMessage();
    std::vector <std::string> getData() const ;
    void SetUsername(std::string username);
    void setPassword(std::string password);
};