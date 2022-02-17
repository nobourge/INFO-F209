#include <iostream>
#include "client_mvc_factory.h"

int main() {
  EnumFactory::SelectionableMenu enumf =EnumFactory::Login;
  while(true){
  AbstractController* control;
  ClientMVCFactory mvc;
  control = mvc.getController(enumf);
  enumf = control->Control();
  }
  return 0;
}
