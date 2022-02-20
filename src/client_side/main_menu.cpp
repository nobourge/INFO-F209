#include "main_menu.hpp"


///
/// \return
std::vector <bool> MainMenu::getButtonState() const{
    return buttons;
}

///
/// \param message
void MainMenu::ReceiveMessage(std::string message){
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

///
/// \return
EnumFactory::SelectionableMenu MainMenu::ReceiveEnterMessage(){
if (current_index==4){
  return EnumFactory::Login;
}
  if (current_index==3){
    return EnumFactory::Help;
  }
  if (current_index==0){
    return EnumFactory::TypeOfGameSelect;
  }
return EnumFactory::null;
}

///
/// \return
std::vector <bool> Login::getButtonState() const{
  return buttons;
}

///
/// \param username
void Login::SetUsername(std::string username){
    data[0] = username ;
}

///
/// \param password
void Login::setPassword(std::string password){
    //vérification
    data[1] = password ;
}

///
/// \return
EnumFactory::SelectionableMenu Login::ReceiveEnterMessage(){
    if(current_index==0){
        return EnumFactory::Pseudo;
    }
    if(current_index==1){
        return EnumFactory::MDP;
    }
    if(current_index==2){
        if (data[0] != "" && data[1] != "")
            return EnumFactory::Main;
    }
    if(current_index==3){
        return EnumFactory::StartScreen;
    }
    return EnumFactory::null;
}

std::vector<std::string> Login::getData() const {
    if(data[0] != "" &&  data[1] != ""){
        return data;
    }
}

///
/// \param message
void Login::ReceiveMessage(std::string message){
  if (message == "259"){
    current_index-=1;
  }else if (message == "258"){
    current_index+=1;
  }
  buttons = {false, false, false, false};
  if(current_index<0)current_index=0;
  if(current_index>buttons.size()-1)current_index=buttons.size()-1;
  buttons[current_index]=true;
}

///
/// \return
EnumFactory::SelectionableMenu Help::ReceiveEnterMessage(){
    return EnumFactory::Main;
}

///
/// \return
std::vector <bool> StartScreen::getButtonState() const{
  return buttons;
}

///
/// \param message
void StartScreen::ReceiveMessage(std::string message){
  if (message == "259"){
    current_index-=1;
  }else if (message == "258"){
    current_index+=1;
  }
  buttons = {false, false, false};
  if(current_index<0)current_index=0;
  if(current_index>buttons.size()-1)current_index=buttons.size()-1;
  buttons[current_index]=true;
}

///
/// \return
EnumFactory::SelectionableMenu StartScreen::ReceiveEnterMessage(){
  if (current_index==0){
    return EnumFactory::Login;
  }
  if (current_index==1){
    return EnumFactory::SignUp;
  }
  if (current_index==2){
    return EnumFactory::Exit;
  }
  return EnumFactory::null;
}

///
/// \return
std::vector <bool> TypeOfGameSelect::getButtonState() const{
  return buttons;
}

///
/// \param message
void TypeOfGameSelect::ReceiveMessage(std::string message){
  if (message == "259"){
    current_index-=1;
  }else if (message == "258"){
    current_index+=1;
  }
  buttons = {false, false, false};
  if(current_index<0)current_index=0;
  if(current_index>buttons.size()-1)current_index=buttons.size()-1;
  buttons[current_index]=true;
}

///
/// \return
EnumFactory::SelectionableMenu TypeOfGameSelect::ReceiveEnterMessage(){
  if (current_index==2){
    return EnumFactory::Main;
  }
  return EnumFactory::null;
}

///
/// \return
std::vector <bool> SignUp::getButtonState() const{
  return buttons;
}

///
/// \param username
void SignUp::SetUsername(std::string username){
  data[0] = username ;
}

///
/// \param password
void SignUp::setfirstPassword(std::string password){
  //vérification
  data[1] = password ;
}

///
/// \param password
void SignUp::setsecondPassword(std::string password){
  //vérification
  data[2] = password ;
}

///
/// \return
EnumFactory::SelectionableMenu SignUp::ReceiveEnterMessage(){
  if(current_index==0)
    return EnumFactory::Pseudo;
  if(current_index==1)
    return EnumFactory::MDP;
  if(current_index==2)
    return EnumFactory::MDP2;
  if(current_index==3){
    if(data[0] != "" &&  data[1] != "")
      return EnumFactory::Main;
  }
  if(current_index==4){
      return EnumFactory::StartScreen;
  }
  return EnumFactory::null;
}

///
/// \return
std::vector<std::string> SignUp::getData() const {
  if(data[0] != "" &&  data[1] != ""){
    return data;
  }
}

///
/// \param message
void SignUp::ReceiveMessage(std::string message){
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