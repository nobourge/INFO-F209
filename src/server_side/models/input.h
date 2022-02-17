#include<iostream>
#include"common.h"

using namespace std;

class Input{
public:
    char getInput();
    DIRECTION getInputMovement();
    string getInputWall();
};