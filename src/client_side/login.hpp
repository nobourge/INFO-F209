#include <iostream>
#include <vector>
using namespace std;

class Login{
    vector <string> data={"",""};
public:
    vector <string> getData() const ;
    void SetUsername(string username);
    void setPassword(string password);
};
