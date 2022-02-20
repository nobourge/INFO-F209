#include"database.h"

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

void DataBase::createTables(){
    //Create first table PLAYER(USER)
    sql = "CREATE TABLE IF NOT EXISTS PLAYER("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "PSEUDO           TEXT    NOT NULL, "
                      "PASSWORD           TEXT    NOT NULL, "
                      "FRIENDS           TEXT    NOT NULL, "
                      "SCORE           INT    NOT NULL, "
                      "ROW         INT NOT NULL, "
                      "COL         INT NOT NULL,"
                      "DIRECTION         INT NOT NULL)";
    exit = sqlite3_open("example.db", &DB);
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    //Create second table BOARD
    sql="CREATE TABLE IF NOT EXISTS BOARD("
                      "PAWNS           INT    NOT NULL, "
                      "WALLS        INT NOT NULL)";

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    
    //Create third table RANKING
    sql="CREATE TABLE IF NOT EXISTS RANKING("
                      "FIRST_PLACE           TEXT    NOT NULL, "
                      "SECOND_PLACE           TEXT    NOT NULL, "
                      "THIRD_PLACE           TEXT    NOT NULL, "
                      "FOURTH_PLACE        TEXT NOT NULL)";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    //Create fourth table FRIENDS
    sql="CREATE TABLE IF NOT EXISTS FRIENDS("
                      "FRIENDS        TEXT NOT NULL)";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    //Create fifth table CONVERSATIONS
    sql="CREATE TABLE IF NOT EXISTS CONVERSATIONS("
                      "CONVERSATIONS       TEXT NOT NULL)";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);


    //Verify table
    verifyTable();
    //Close db
    sqlite3_close(DB);
}

void DataBase::inserPlayer(shared_ptr<Player>player){
    exit = sqlite3_open("example.db", &DB);
    int row=player->getPlayerPos().row;
    int col=player->getPlayerPos().col;
    string pseudo; //TO be completed later by the server.
    DIRECTION dr=player->getGoal();


    //Insert in the table
    string query = "SELECT * FROM PLAYER;";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    sql=("INSERT INTO PLAYER VALUES(1, 'PSEUDO', 'NONE', 'NONE',0," + to_string(row) +"," + to_string(col) +"," + to_string(dr) + ");");
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    //Verify creation of table
    verifyTable();
    //Close db
    sqlite3_close(DB);
}

void DataBase::insertBoard(int nrOfPlayers,int nrOfWalls){
    exit = sqlite3_open("example.db", &DB);

    //Insert in the table
    string query = "SELECT * FROM BOARD;";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    //Insert values
    sql=("INSERT INTO BOARD VALUES("+to_string(nrOfPlayers) +"," + to_string(nrOfWalls) + ");");
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    verifyTable();
    sqlite3_close(DB);
}

void DataBase::verifyTable(){
      if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
}