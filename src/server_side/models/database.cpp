#include"database.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include<cstring>

int DataBase::friendsId=0;

void DataBase::reloadFile(std::string file){
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

void DataBase::createTables(){
    //Create first table USER
    sql = "CREATE TABLE IF NOT EXISTS USER("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "PSEUDO           TEXT    NOT NULL, "
                      "PASSWORD           TEXT    NOT NULL, "
                      "FRIENDS           TEXT    NOT NULL, "
                      "SCORE           INT    NOT NULL)";

    reloadFile("example.db");

    exit = sqlite3_open("example.db", &DB);
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
                      "PLAYER_ID INT NOT NULL, "
                      "FIRST_PLACE           TEXT    NOT NULL, "
                      "SECOND_PLACE           TEXT    NOT NULL, "
                      "THIRD_PLACE           TEXT    NOT NULL, "
                      "FOURTH_PLACE        TEXT NOT NULL)";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    //Create fourth table FRIENDS
    sql="CREATE TABLE IF NOT EXISTS FRIENDS("
                      "ID INT PRIMARY KEY NOT NULL, "
                      "MY_USER_ID INT NOT NULL, "
                      "MY_FRIEND_ID        INT NOT NULL)";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    //Create fifth table CONVERSATIONS
    sql="CREATE TABLE IF NOT EXISTS CONVERSATIONS("
                      "ID INT PRIMARY KEY NOT NULL, "
                      "PLAYER_ID INT NOT NULL, "
                      "CONVERSATIONS       TEXT NOT NULL)";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);


    //Verify table
    verifyTable();
    //Close db
    sqlite3_close(DB);
}

void DataBase::insertPlayer(unsigned int id){
    exit = sqlite3_open("example.db", &DB);
    string pseudo; //TO be completed later by the server.


    //Insert in the table
    string query = "SELECT * FROM USER;";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    sql=("INSERT INTO USER VALUES("+to_string(id)+",'PSEUDO','NONE','NONE',0);");
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    //Verify creation of table
    verifyTable();
    //Close db
    sqlite3_close(DB);
}

void DataBase::insertFriend(int myId,int myFriendId){
    exit = sqlite3_open("example.db", &DB);

    string query = "SELECT * FROM FRIENDS;";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    //Insert the friend-me and me-friend relation into the data base
    sql=("INSERT INTO FRIENDS VALUES("+to_string(friendsId)+","+to_string(myId)+ "," + to_string(myFriendId)+");");
    friendsId++;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    sql=("INSERT INTO FRIENDS VALUES("+to_string(friendsId)+","+to_string(myFriendId)+ "," + to_string(myId)+");");
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    friendsId++;

    verifyTable();
    sqlite3_close(DB);
}

void DataBase::searchFriends(int id){
    exit = sqlite3_open("example.db", &DB);
    
    string data("CALLBACK FUNCTION");
    string query = "SELECT MY_FRIEND_ID FROM FRIENDS WHERE FRIENDS.MY_USER_ID="+to_string(id)+";";
    sqlite3_exec(DB, query.c_str(), callback, (void*)data.c_str(), NULL); 
    

    sqlite3_close(DB);
}

void DataBase::insertBoard(int nrOfPlayers,int nrOfWalls){
    exit = sqlite3_open("example.db", &DB);

    //Insert in the table
    string query = "SELECT * FROM BOARD;";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    //Insert values
    sql=("INSERT INTO BOARD VALUES(1,"+to_string(nrOfPlayers) +"," + to_string(nrOfWalls) + ");");
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