#include <iostream>
#include "answer.h"
#include "client_mvc_factory.h"

int main() {
  AbstractController* control;
  ClientMVCFactory mvc;
  control = mvc.getController(ClientMVCFactory::Login);
  control->Control();
  return 0;
}
