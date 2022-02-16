//
// Created by guest on 16/02/2022.
//

#include "client_mvc_factory.h"
AbstractController* ClientMVCFactory:: getController(string mvcname){
  switch(mvcname){
    case "Main":
      return new ControllerMainMenu;
      break;
  }
}