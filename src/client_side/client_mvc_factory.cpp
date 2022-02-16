#include <string>
#include "client_mvc_factory.h"
#include "controller.h"
#include "abstract_controller.h"


AbstractController* ClientMVCFactory::getController(SelectionableMenu mvcname){
  switch(mvcname){
    case Main:
      return new ControllerMainMenu;
      break;
  }
}