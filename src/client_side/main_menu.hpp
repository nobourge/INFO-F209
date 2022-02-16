#include <iostream>
#include <vector>

class MainMenu{
    std::vector<bool> buttons = {false, false, true, false, false};
    int current_index = 2;
public:
    std::vector <bool> getButtonState() const ;
    void ReceiveMessage(std::string message);
};