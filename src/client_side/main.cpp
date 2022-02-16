#include <iostream>
#include "answer.h"
#include "controller.h"
#include "client_mvc_factory.h"
int main() {
  AbstractController* control;
  ClientMVCFactory mvc;
  control =mvc.getController("Main");
  control->Control();
  return 0;
}
