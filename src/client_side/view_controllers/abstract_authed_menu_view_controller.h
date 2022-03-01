//
// Created by Anton Romanova on 28/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_AUTHED_MENU_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_AUTHED_MENU_VIEW_CONTROLLER_H_

#include "abstract_menu_view_controller.h"


class AbstractAuthedMenuViewController: public AbstractMenuViewController {
public:
  AbstractAuthedMenuViewController(
      const std::shared_ptr<AbstractMenuView> &ptr);

protected:
  void MenuViewWillAppear() override;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_AUTHED_MENU_VIEW_CONTROLLER_H_
