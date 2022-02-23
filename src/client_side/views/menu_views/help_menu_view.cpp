#include <ncurses.h>
#include <cstring>
#include <vector>
#include <memory>
#include "help_menu_view.h"
#include "views/label.h"
#include "views/text_field.h"

HelpMenuView::HelpMenuView() : AbstractMenuView(menu_name_) {
  UpdateSubviews({
    std::make_shared<Label>(this, "This is a help label"),
    std::make_shared<MenuButtonItem>(this, "Back", std::optional<std::shared_ptr<AbstractViewController>>{}, this),
    std::make_shared<TextField>(this, "Test", this)
    }
  );
}

void HelpMenuView::TextChanged(const std::string &new_text) {}

void HelpMenuView::TextEditingFinished() {}
