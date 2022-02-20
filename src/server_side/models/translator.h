#include"position.h"
#include<iostream>
#include<vector>

using namespace std;

class translator{
public:
  ///
  /// \return
    bool verifyMove(string,vector<char>);
  ///
  /// \return
    bool verifyNumber(string,vector<string>);
    ///
    /// \return
    Position translateMove(string,int=9);
};