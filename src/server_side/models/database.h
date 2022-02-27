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
  sqlite3* db_;
  std::string sql_;
  int last_sqlite3_exit_code_ =0;
  char* messageError;
  static int friendsId;
  static int ranking_id_;

  DataBase() {}

  static DataBase instance;

public:
  static DataBase& Get(){
    return instance;
  }

  void CreateTables();
  void InsertPlayer(unsigned int id);
  void VerifyTable(std::string= "");
  void InsertBoard(int,int);
  void InsertFriend(int user1_id, int user2_id);
  void SearchFriends(int user_id);
  void InsertRanking(int,int=0,int=0,int=0);
  void UpdateUser(int,int);
  void ReloadFile(std::string);
  records GetSelect(string);
};
