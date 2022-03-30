#include <stack>
#include "view_controllers/view_controller_abstract.h"
#include "view_controllers/view_controller_home_menu.h"
#include "view_controllers/view_controller_welcome.h"
#undef scroll
#include "QtCode/mainmenuview.h"
#include <QApplication>
#include "thread"

//int Qt_thread(int argc, char *argv[]){
//
//}
int main(int argc, char *argv[]) {
//  std::thread t=std::thread(Qt_thread,argc, argv);
//  QApplication q_application(argc, argv);
//  MainMenuView w;
//  w.show();
//  return q_application.exec();
  std::stack<std::shared_ptr<AbstractViewController>> view_controllers{};
  view_controllers.push(std::make_shared<StartViewController>());
  while (!view_controllers.empty()) {
    auto new_view_controller = view_controllers.top()->Tick();

    if (new_view_controller.has_value())
      view_controllers.push(*new_view_controller);
    else
      view_controllers.pop();

  }
  return 0;
}


