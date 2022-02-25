#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sqlite3.h>
#include <memory>
#include <fstream>
#include <string>
#include"Player.h"
#include"position.h"
#include "../../common/constants.h"

using record = std::vector<std::string>;
using records = std::vector<record>;

class DataBase{
  sqlite3* DB;
  std::string sql;
  int exit=0;
  char* messageError;
  static int friendsId;
  static int rankingId;
public:
  void createTables();
  void insertPlayer(unsigned int);
  void verifyTable(std::string="");
  void insertBoard(int,int);
  void insertFriend(int,int);
  void searchFriends(int);
  void insertRanking(int,int=0,int=0,int=0);
  void updateUser(int,int);
  void reloadFile(std::string);
  records getSelect(string);
};
