#include <memory>
#include "login_menu_view.h"
#include "views/label.h"
#include "views/text_field.h"
#include "../../view_controllers/home_menu_view_controller.h"

LoginMenuView::LoginMenuView() : AbstractMenuView(menu_name_) {
  UpdateSubviews({
    std::make_shared<Label>(this, "Insert your Pseudo"),
    std::make_shared<TextField>(this, "", this),
    std::make_shared<Label>(this, "Insert your Password"),
    std::make_shared<TextField>(this, "", this),
    std::make_shared<MenuButtonItem>(this, "Continue", std::make_shared<HomeMenuViewController>(), this),
    std::make_shared<MenuButtonItem>(this, "Quit", std::optional<std::shared_ptr<AbstractViewController>>{}, this),
    }
  );
}

void LoginMenuView::TextChanged(TextField &sender, const std::string &old_text) {
  if (old_text.size() < sender.GetInnerText().size()
      &&
      *(--sender.GetInnerText().end()) != ' ')
  {
    sender.SetInnerText(sender.GetInnerText() + ' ');
  }
}

void LoginMenuView::TextEditingFinished(TextField &sender) {
//  sender.SetInnerText("This TextField has been altered");
}
