#include "database.h"

int DataBase::friendsId = 0;
int DataBase::ranking_id_ = 0;

void DataBase::ReloadFile(std::string file) {
  ifstream ifile;
  int n = file.length();
  char file2[n + 1];
  strcpy(file2, file.c_str());

  ifile.open(file2);
  if (ifile) {
    remove(file2);
  }
}

static int callback(void *data, int argc, char **argv, char **azColName) {
  fprintf(stderr, "%s: ", (const char *)data);

  for (int i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }

  printf("\n");
  return 0;
}

static int select_callback(void *data, int argc, char **argv, char **colName) {

  records *res = static_cast<records *>(data);

  res->emplace_back(argv, argv + argc);

  return 0;
}

records DataBase::GetSelect(std::string statement) {

  records res;

  last_sqlite3_exit_code_ = sqlite3_open(DATABASE_FILE_NAME, &db_);

  last_sqlite3_exit_code_ =
      sqlite3_exec(db_, statement.c_str(), select_callback, &res, nullptr);

  sqlite3_close(db_);

  if (last_sqlite3_exit_code_ != SQLITE_OK) {
    std::cout << "Database error: " << sqlite3_errstr(last_sqlite3_exit_code_)
              << std::endl;
  } else {
    std::cout << res.size() << " records returned" << std::endl;
  }
  return res;
}

void DataBase::CreateTables() {
  // Create first table USER
  sql_ = "CREATE TABLE IF NOT EXISTS USER("
         "ID INTEGER PRIMARY KEY, "
         "PSEUDO         TEXT    NOT NULL, "
         "PASSWORD       TEXT    NOT NULL, "
         "TIMESTAMP      TEXT    NOT NULL, "
         "SCORE          INT     NOT NULL)";

  //  ReloadFile("example.db");

  last_sqlite3_exit_code_ = sqlite3_open(DATABASE_FILE_NAME, &db_);
  last_sqlite3_exit_code_ =
      sqlite3_exec(db_, sql_.c_str(), nullptr, nullptr, &messageError);
  // Create second table BOARD
  sql_ = "CREATE TABLE IF NOT EXISTS BOARD("
         "ID PRIMARY KEY NOT NULL, "
         "PAWNS           INT    NOT NULL, "
         "WALLS        INT NOT NULL)";

  last_sqlite3_exit_code_ =
      sqlite3_exec(db_, sql_.c_str(), nullptr, nullptr, &messageError);

  // Create third table RANKING
  sql_ = "CREATE TABLE IF NOT EXISTS RANKING("
         "ID  INT PRIMARY KEY NOT NULL, "
         "FIRST_PLACE           INT    NOT NULL, "
         "SECOND_PLACE           INT    NOT NULL, "
         "THIRD_PLACE           INT    NOT NULL, "
         "FOURTH_PLACE        INT NOT NULL)";
  last_sqlite3_exit_code_ =
      sqlite3_exec(db_, sql_.c_str(), nullptr, nullptr, &messageError);

  // Create fourth table FRIENDS
  sql_ = "CREATE TABLE IF NOT EXISTS FRIENDS("
         "ID INT PRIMARY KEY NOT NULL, "
         "MY_USER_ID INT NOT NULL, "
         "MY_FRIEND_ID INT NOT NULL, "
         "PORT        INT NOT NULL)";
  last_sqlite3_exit_code_ =
      sqlite3_exec(db_, sql_.c_str(), nullptr, nullptr, &messageError);

  // Create fifth table CONVERSATIONS
  sql_ = "CREATE TABLE IF NOT EXISTS CONVERSATIONS("
         "ID INTEGER PRIMARY KEY, "
         "SENDER_ID     INT NOT NULL, "
         "RECEIVER_ID   INT NOT NULL, "
         "TIMESTAMP     INT NOT NULL, "
         "CONTENT       TEXT NOT NULL)";
  last_sqlite3_exit_code_ =
      sqlite3_exec(db_, sql_.c_str(), nullptr, nullptr, &messageError);

  // Verify table
  VerifyTable("Creating tables");
  // Close db
  sqlite3_close(db_);
}

void DataBase::InsertMessage(const int sender_id, const int receiver_id, int64_t timestamp, const string content) {
  last_sqlite3_exit_code_ = sqlite3_open(DATABASE_FILE_NAME, &db_);

  sql_ = "INSERT INTO CONVERSATIONS (SENDER_ID, RECEIVER_ID, TIMESTAMP, CONTENT) VALUES(" +
      to_string(sender_id) + "," + to_string(receiver_id) + "," + to_string(timestamp) + ",\"" +
      content + "\");";

  last_sqlite3_exit_code_ = sqlite3_exec(db_, sql_.c_str(), callback, nullptr, &messageError);

  // Verify creation of table
  VerifyTable("Insert message into conversation");
  // Close db
  sqlite3_close(db_);
}

void DataBase::InsertPlayer(const string &username, const string &password,
                            int64_t timestamp, uint32_t score) {
  last_sqlite3_exit_code_ = sqlite3_open(DATABASE_FILE_NAME, &db_);
  string pseudo; // TO be completed later by the server.

  // Insert in the table
  sql_ = "INSERT INTO USER (PSEUDO, PASSWORD, TIMESTAMP, SCORE) VALUES(\"" +
         username + "\",\"" + password + "\"," + to_string(timestamp) + "," +
         to_string(score) + ");";
  last_sqlite3_exit_code_ =
      sqlite3_exec(db_, sql_.c_str(), callback, nullptr, &messageError);

  // Verify creation of table
  VerifyTable("Insert values into player");
  // Close db
  sqlite3_close(db_);
}

void DataBase::InsertFriend(int user1_id, int user2_id) {
  last_sqlite3_exit_code_ = sqlite3_open(DATABASE_FILE_NAME, &db_);

  string query = "SELECT * FROM FRIENDS;";
  sqlite3_exec(db_, query.c_str(), callback, nullptr, nullptr);
  // Insert the friend-me and me-friend relation into the database
  sql_ = ("INSERT INTO FRIENDS VALUES(" + to_string(friendsId) + "," +
          to_string(user1_id) + "," + to_string(user2_id) + ",0);");
  friendsId++;
  last_sqlite3_exit_code_ =
      sqlite3_exec(db_, sql_.c_str(), nullptr, nullptr, &messageError);

  VerifyTable("Insert values into friend");
  sqlite3_close(db_);
}

std::unordered_set<uint32_t> DataBase::SearchFriends(object_id_t user_id) {
  last_sqlite3_exit_code_ = sqlite3_open(DATABASE_FILE_NAME, &db_);

  std::string current_user_id_str = std::to_string(user_id);

  string data("CALLBACK FUNCTION");
  string query =
      "SELECT MY_USER_ID, MY_FRIEND_ID FROM FRIENDS WHERE FRIENDS.MY_FRIEND_ID=" +
      current_user_id_str + " OR FRIENDS.MY_USER_ID=" + current_user_id_str +
      ";";

  auto query_res = GetSelect(query);
  std::unordered_set<object_id_t> friends = {};
  friends.reserve(query_res.size());
  for (const std::vector<std::string> &friend_string_repr : query_res) {
    std::string other_user_id_str =
        friend_string_repr[friend_string_repr[0] == current_user_id_str ? 1
                                                                        : 0];

    friends.insert(std::stoul(other_user_id_str));
  }
  return friends;
}

void DataBase::InsertRanking(int firstPlaceId, int secondPlaceId,
                             int thirdPlaceId, int fourthPlaceId) {
  last_sqlite3_exit_code_ = sqlite3_open(DATABASE_FILE_NAME, &db_);

  string query = "SELECT * FROM RANKING;";
  sqlite3_exec(db_, query.c_str(), callback, nullptr, nullptr);

  // Only 2 players played this match.
  if (thirdPlaceId == 0 && fourthPlaceId == 0) {
    sql_ =
        ("INSERT INTO RANKING VALUES(" + to_string(ranking_id_) + "," +
         to_string(firstPlaceId) + "," + to_string(secondPlaceId) + ",0,0);");
    ranking_id_++;
    last_sqlite3_exit_code_ =
        sqlite3_exec(db_, sql_.c_str(), nullptr, nullptr, &messageError);
  } else {
    sql_ = ("INSERT INTO RANKING VALUES(" + to_string(ranking_id_) + "," +
            to_string(firstPlaceId) + "," + to_string(secondPlaceId) + "," +
            to_string(thirdPlaceId) + "," + to_string(fourthPlaceId) + ");");
    ranking_id_++;
    last_sqlite3_exit_code_ =
        sqlite3_exec(db_, sql_.c_str(), nullptr, nullptr, &messageError);
  }

  VerifyTable("Insert values into the ranking");
  sqlite3_close(db_);
}

void DataBase::UpdateUser(uint32_t score, uint32_t id) {
  last_sqlite3_exit_code_ = sqlite3_open(DATABASE_FILE_NAME, &db_);

  // Update Table
  string query = "UPDATE USER SET SCORE=" + to_string(score) +
                 " WHERE ID=" + to_string(id) + ";";
  sqlite3_exec(db_, query.c_str(), callback, nullptr, nullptr);

  sqlite3_close(db_);
}

void DataBase::InsertBoard(int nrOfPlayers, int nrOfWalls) {
  last_sqlite3_exit_code_ = sqlite3_open(DATABASE_FILE_NAME, &db_);

  // Insert in the table
  string query = "SELECT * FROM BOARD;";
  sqlite3_exec(db_, query.c_str(), callback, nullptr, nullptr);
  // Insert values
  sql_ = ("INSERT INTO BOARD VALUES(1," + to_string(nrOfPlayers) + "," +
          to_string(nrOfWalls) + ");");
  last_sqlite3_exit_code_ =
      sqlite3_exec(db_, sql_.c_str(), nullptr, nullptr, &messageError);

  VerifyTable("Insert values into the board");
  sqlite3_close(db_);
}

void DataBase::VerifyTable(const string &message) {
  cout << message << " ";
  if (last_sqlite3_exit_code_ != SQLITE_OK) {
    std::cerr << "Error Create Table: "
              << sqlite3_errstr(last_sqlite3_exit_code_) << std::endl;
    sqlite3_free(messageError);
  } else
    std::cout << "Table created Successfully" << std::endl;
}

DataBase *DataBase::GetInstance() {
  static bool initialized = false;
  static DataBase db;
  if (!initialized) {
    db.CreateTables();
    initialized = true;
  }

  return &db;
}
