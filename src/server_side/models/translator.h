#include"position.h"
#include<iostream>
#include<vector>

using namespace std;

class translator{
public:
    bool verifyMove(string,vector<char>);
    bool verifyNumber(string,vector<string>);
    Position translateMove(string,int=9);
};