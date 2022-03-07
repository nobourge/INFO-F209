#include "../views/menu_views/home_menu_view.h"
#include "view_controller_menu_abstract.h"
#include "view_controller_menu_abstract_authed.h"
#include <string>

#ifndef QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_

class HomeMenuViewController : public AbstractAuthedMenuViewController, public MenuButtonItemDelegate {
 public:
   HomeMenuViewController();
   void PresentController(
       const std::optional<std::shared_ptr<AbstractViewController>> &destination, MenuButtonItem &sender) override;

 public:
   std::shared_ptr<MenuButtonItem> logout_button_;
};



#endif //QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_
