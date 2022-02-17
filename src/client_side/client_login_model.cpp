#include "client_login_model.hpp"

std::vector <bool> Login::getButtonState() const{
  return buttons;
}
void Login::SetUsername(string username){
    data[0] = username ;
}

void Login::setPassword(string password){
    //vérification
    data[1] = password ;
}
int Login::ReceiveEnterMessage(){
    //10 == enter (normalement)
    // fonction doit : verifier enter en fonction de où est le bouton et renvoyer enum
//    if (message == "10"){
//        return ClientMVCFactory::Login;
//    }
}


vector <string> Login::getData() const {
    if(data[0] != "" &&  data[1] != ""){
        return data;
    }
}
void Login::ReceiveMessage(std::string message){
  if (message == "259"){
    current_index-=1;
  }else if (message == "258"){
    current_index+=1;
  }
  buttons = {false, false, false, false, false};
  if(current_index<0)current_index=0;
  if(current_index>buttons.size()-1)current_index=buttons.size()-1;
  buttons[current_index]=true;
}
