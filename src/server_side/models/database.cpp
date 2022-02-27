#include"database.h"


int DataBase::friendsId=0;
int DataBase::rankingId=0;

void DataBase::ReloadFile(std::string file){
  ifstream ifile;
  int n=file.length();
  char file2[n+1];
  strcpy(file2,file.c_str());

  ifile.open(file2);
  if(ifile) {
    remove(file2);
  }
}

static int callback(void* data, int argc, char** argv, char** azColName)
{
  int i;
  fprintf(stderr, "%s: ", (const char*)data);

  for (i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }

  printf("\n");
  return 0;
}

static int select_callback(void *data, int argc, char **argv, char **colName) {

  records *res = static_cast<records*>(data);

  res->emplace_back(argv, argv + argc);

  return 0;
}

records DataBase::GetSelect(std::string statement) {

  records res;

  exit = sqlite3_open(DATABASE_FILE_NAME, &DB);

  exit = sqlite3_exec(DB, statement.c_str(), select_callback, &res,  NULL);

  sqlite3_close(DB);

  if (exit != SQLITE_OK) {
    std::cout<<"error"<<std::endl;
  } else {
    std::cout<<res.size()<<" records returned"<<std::endl;
  }
  return res;

}

void DataBase::CreateTables(){
    //Create first table USER
    sql = "CREATE TABLE IF NOT EXISTS USER("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "PSEUDO           TEXT    NOT NULL, "
                      "PASSWORD           TEXT    NOT NULL, "
                      "FRIENDS           TEXT    NOT NULL, "
                      "SCORE           INT    NOT NULL)";

    ReloadFile("example.db");

    exit = sqlite3_open(DATABASE_FILE_NAME, &DB);
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    //Create second table BOARD
    sql="CREATE TABLE IF NOT EXISTS BOARD("
                      "ID PRIMARY KEY NOT NULL, "
                      "PAWNS           INT    NOT NULL, "
                      "WALLS        INT NOT NULL)";

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    //Create third table RANKING
    sql="CREATE TABLE IF NOT EXISTS RANKING("
                      "ID  INT PRIMARY KEY NOT NULL, "
                      "FIRST_PLACE           INT    NOT NULL, "
                      "SECOND_PLACE           INT    NOT NULL, "
                      "THIRD_PLACE           INT    NOT NULL, "
                      "FOURTH_PLACE        INT NOT NULL)";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    //Create fourth table FRIENDS
    sql="CREATE TABLE IF NOT EXISTS FRIENDS("
                      "ID INT PRIMARY KEY NOT NULL, "
                      "MY_USER_ID INT NOT NULL, "
                      "MY_FRIEND_ID INT NOT NULL, "
                      "PORT        INT NOT NULL)";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    //Create fifth table CONVERSATIONS
    sql="CREATE TABLE IF NOT EXISTS CONVERSATIONS("
                      "ID INT PRIMARY KEY NOT NULL, "
                      "PLAYER_ID INT NOT NULL, "
                      "CONVERSATIONS       TEXT NOT NULL)";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);


    //Verify table
    VerifyTable("Creating tables");
    //Close db
    sqlite3_close(DB);
}

void DataBase::InsertPlayer(unsigned int id) {
    exit = sqlite3_open(DATABASE_FILE_NAME, &DB);
    string pseudo; //TO be completed later by the server.


    //Insert in the table
    string query = "SELECT * FROM USER;";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    sql=("INSERT INTO USER VALUES("+to_string(id)+",'PSEUDO','NONE','NONE',0);");
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    //Verify creation of table
    VerifyTable("Insert values into player");
    //Close db
    sqlite3_close(DB);
}

void DataBase::InsertFriend(int user1_id, int user2_id) {
    exit = sqlite3_open(DATABASE_FILE_NAME, &DB);

    string query = "SELECT * FROM FRIENDS;";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    //Insert the friend-me and me-friend relation into the database
    sql=("INSERT INTO FRIENDS VALUES("+to_string(friendsId)+","+to_string(user1_id)+ "," + to_string(user2_id)+",0);");
    friendsId++;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    sql=("INSERT INTO FRIENDS VALUES("+to_string(friendsId)+","+to_string(user2_id)+ "," + to_string(user1_id)+",0);");
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    friendsId++;

    VerifyTable("Insert values into friend");
    sqlite3_close(DB);
}

void DataBase::SearchFriends(int user_id) {
    exit = sqlite3_open(DATABASE_FILE_NAME, &DB);

    string data("CALLBACK FUNCTION");
    string query = "SELECT MY_FRIEND_ID FROM FRIENDS WHERE FRIENDS.MY_USER_ID="+to_string(user_id)+";";
    sqlite3_exec(DB, query.c_str(), callback, (void*)data.c_str(), NULL);


    sqlite3_close(DB);
}


void DataBase::InsertRanking(int firstPlaceId,int secondPlaceId,int thirdPlaceId,int fourthPlaceId){
    exit = sqlite3_open(DATABASE_FILE_NAME, &DB);

    string query = "SELECT * FROM RANKING;";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    //Only 2 players played this match.
    if(thirdPlaceId==0 && fourthPlaceId==0){
        sql=("INSERT INTO RANKING VALUES("+to_string(rankingId)+","+to_string(firstPlaceId)+ "," + to_string(secondPlaceId)+",0,0);");
        rankingId++;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    }else{
        sql=("INSERT INTO RANKING VALUES("+to_string(rankingId)+","+to_string(firstPlaceId)+ "," + to_string(secondPlaceId)+","+to_string(thirdPlaceId)+","+to_string(fourthPlaceId)+");");
        rankingId++;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    }

    VerifyTable("Insert values into the ranking");
    sqlite3_close(DB);
}

void DataBase::UpdateUser(int score,int id){
    exit = sqlite3_open(DATABASE_FILE_NAME, &DB);

    //Update Table
    string query = "UPDATE USER SET SCORE="+to_string(score)+" WHERE ID="+to_string(id)+";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);

}

void DataBase::InsertBoard(int nrOfPlayers,int nrOfWalls){
    exit = sqlite3_open(DATABASE_FILE_NAME, &DB);

    //Insert in the table
    string query = "SELECT * FROM BOARD;";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    //Insert values
    sql=("INSERT INTO BOARD VALUES(1,"+to_string(nrOfPlayers) +"," + to_string(nrOfWalls) + ");");
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    VerifyTable("Insert values into the board");
    sqlite3_close(DB);
}

void DataBase::VerifyTable(string message){
      cout<<message<<" ";
      if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
}
