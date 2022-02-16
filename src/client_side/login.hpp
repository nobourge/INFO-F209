#include <iostream>
#include <vector>
#include "client_mvc_factory.h"
using namespace std;

class Login{
    vector <string> data={"",""};
public:
    int ReceiveMessage(string message);
    vector <string> getData() const ;
    void SetUsername(string username);
    void setPassword(string password);
};
