#include <iostream>
#include "view_controllers/abstract_view_controller.h"
#include "view_controllers/home_menu_view_controller.h"

int main() {
  std::optional<std::shared_ptr<AbstractViewController>> view_controller = std::make_shared<HomeMenuViewController>();
  while (view_controller.has_value()) {
    view_controller = (*view_controller)->Tick();
  }
  return 0;
}
