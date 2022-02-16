#include <login.hpp>


void Login::SetUsername(string username){
    data[0] = username ;
}

void Login::setPassword(string password){
    data[1] = password ;
}

vector <string> Login::getData() const {
    if(data[0] != "" &&  data[1] != ""){
        return data;
    }
}