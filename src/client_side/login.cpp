#include <login.hpp>


void Login::SetUsername(string username){
    data[0] = username ;
}

void Login::setPassword(string password){
    //vérification
    data[1] = password ;
}
int Login::ReceiveMessage(string message){
    //10 == enter (normalement)
    // fonction doit : verifier enter en fonction de où est le bouton et renvoyer enum
    if (message == "10"){
        return ClientMVCFactory::Login;
    }
}


vector <string> Login::getData() const {
    if(data[0] != "" &&  data[1] != ""){
        return data;
    }
}
