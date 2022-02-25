#include <memory>
#include "help_menu_view.h"
#include "views/label.h"
#include "views/text_field.h"

HelpMenuView::HelpMenuView() : AbstractMenuView(menu_name_) {
  UpdateSubviews({
    std::make_shared<Label>(this, "This is a help label"),
    std::make_shared<MenuButtonItem>(this, "Back", std::optional<std::shared_ptr<AbstractViewController>>{}, this),
    std::make_shared<TextField>(this, "S P A C Y ", this)
    }
  );
}

void HelpMenuView::TextChanged(TextField &sender, const std::string &old_text) {
  if (old_text.size() < sender.GetInnerText().size()
      &&
      *(--sender.GetInnerText().end()) != ' ')
  {
    sender.SetInnerText(sender.GetInnerText() + ' ');
  }
}

void HelpMenuView::TextEditingFinished(TextField &sender) {
//  sender.SetInnerText("This TextField has been altered");
}
