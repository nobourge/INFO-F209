//
// Created by Anton Romanova on 28/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_MENU_ABSTRACT_AUTHED_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_MENU_ABSTRACT_AUTHED_H_

#include "view_controller_menu_abstract.h"


class AbstractAuthedMenuViewController: public AbstractMenuViewController {
public:
  AbstractAuthedMenuViewController(
      const std::shared_ptr<AbstractMenuView> &ptr);

protected:
  void MenuViewWillAppear() override;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_MENU_ABSTRACT_AUTHED_H_
