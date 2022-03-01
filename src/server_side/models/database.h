#include "../../common/constants.h"
#include "Player.h"
#include "position.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <sqlite3.h>
#include <cstdio>
#include <string>
#include <unordered_set>

using record = std::vector<std::string>;
using records = std::vector<record>;

class DataBase {
  sqlite3 *db_;
  std::string sql_;
  int last_sqlite3_exit_code_ = 0;
  char *messageError;
  static int friendsId;
  static int ranking_id_;

  DataBase() {}

public:
  static DataBase *GetInstance();

  void CreateTables();
  void InsertPlayer(const string &username, const string &password,
                    int64_t timestamp, uint32_t score);
  void InsertMessage(const int sender_id, const int receiver_id,
                     int64_t timestamp, const string content);
  void VerifyTable(const string &message);
  void InsertBoard(int nrOfPlayers, int nrOfWalls);
  void InsertFriend(int user1_id, int user2_id);
  std::unordered_set<uint32_t> SearchFriends(object_id_t user_id);
  void InsertRanking(int firstPlaceId, int secondPlaceId, int thirdPlaceId,
                     int fourthPlaceId);
  void UpdateUser(uint32_t score, uint32_t id);
  void ReloadFile(std::string);
  records GetSelect(string);
};
