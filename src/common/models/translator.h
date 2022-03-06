#include"position.h"
#include<iostream>
#include<vector>

using namespace std;

class Translator{ // singleton
  Translator() {}
  static Translator instance;
public:

  static Translator& Get();

  ///
  /// \return
    bool verifyMove(string,vector<char>);
  ///
  /// \return
    bool verifyNumber(string,vector<string>);
    ///
    /// \return
    Position translateMove(string,int=9);

    std::string PositionToMove(const Position, int=9);


};