#include <string>
#include "client_mvc_factory.h"


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