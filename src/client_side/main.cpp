#include <iostream>
#include "answer.h"
#include "client_mvc_factory.h"

int main() {
  AbstractController* control;
  ClientMVCFactory mvc;
  control = mvc.getController(ClientMVCFactory::Main);
  control->Control();
  return 0;
}
