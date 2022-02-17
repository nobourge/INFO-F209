#include <iostream>
#include <vector>
#include "client_mvc_factory.h"
using namespace std;

class Login{
    vector <string> data={"",""};
  std::vector<bool> buttons = {false, false, true, false, false};
  int current_index = 2;
public:
    std::vector <bool> getButtonState() const ;
    void ReceiveMessage(string message);
    int ReceiveEnterMessage();
    vector <string> getData() const ;
    void SetUsername(string username);
    void setPassword(string password);
};
