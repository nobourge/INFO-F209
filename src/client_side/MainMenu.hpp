#include <iostream>
#include <vector>

using namespace std ;


class MainMenu{
    vector<bool> buttons = {false, false, true, false, false};
    int current index = 2;
public:
    vector <bool> getButtonState() const ;
    void ReceiveMessage(string message);
};