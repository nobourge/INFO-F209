#include<iostream>
#include"Player.h"
#include"position.h"
#include<sqlite3.h>
#include<memory>

class DataBase{
    sqlite3* DB;
    std::string sql;
    int exit=0;
    char* messageError;
public:
    void createTables();
    void inserPlayer(std::shared_ptr<Player>);
    void verifyTable();
    void insertBoard(int,int);

};