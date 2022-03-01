//
// Created by Anton Romanova on 28/02/2022.
//

#include "abstract_authed_menu_view_controller.h"
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
