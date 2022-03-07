//
// Created by Anton Romanova on 28/02/2022.
//

#include "view_controller_menu_abstract_authed.h"
#include "../models/api_wrapper.h"

void AbstractAuthedMenuViewController::MenuViewWillAppear() {
  AbstractMenuViewController::MenuViewWillAppear();
  if (!ApiWrapper::GetShared().has_value()) {
    AbstractMenuViewController::PresentViewController({});
  }
}

AbstractAuthedMenuViewController::AbstractAuthedMenuViewController(
    const std::shared_ptr<AbstractMenuView> &ptr)
    : AbstractMenuViewController(ptr) {}
