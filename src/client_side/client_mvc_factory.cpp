#include <string>



AbstractController* ClientMVCFactory::getController(EnumFactory::SelectionableMenu  mvcname){
  switch(mvcname){
    case EnumFactory::Main:
      return new ControllerMainMenu;
      break;
    case EnumFactory::Login:
      return new ControllerLoginClient;
      break;
  }
}