#include <iostream>
#include "client_mvc_factory.h"

int main() {
  AbstractController* control;
  ClientMVCFactory mvc;
  control = mvc.getController(EnumFactory::Login);
  control->Control();
  return 0;
}
