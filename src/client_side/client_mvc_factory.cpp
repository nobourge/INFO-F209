#include <string>
#include "client_mvc_factory.h"


AbstractController* ClientMVCFactory::getController(SelectionableMenu mvcname){
  switch(mvcname){
    case Main:
      return new ControllerMainMenu;
      break;
    case Login:
      return new ControllerLoginClient;
      break;
  }
}