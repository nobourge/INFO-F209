
#include "home_menu_view.h"

HomeMenuView::HomeMenuView() : AbstractMenuView(menu_name_) {}
bool HomeMenuView::ShouldDisplayDefaultBackButton() const {
  return false;
}
