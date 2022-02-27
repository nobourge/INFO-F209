#include "views/label.h"
#include "views/text_field.h"
#include "chat_room_menu_view.h"
#include <memory>


ChatRoomMenuView::ChatRoomMenuView() : AbstractMenuView(menu_name_) {
  UpdateSubviews({
                     std::make_shared<Label>(this, "msg1"),
                     std::make_shared<Label>(this, "msg2"),
                     std::make_shared<Label>(this, "msg3"),
                     std::make_shared<TextField>(this, "Text", this),
                     std::make_shared<MenuButtonItem>(this, "Back", std::optional<std::shared_ptr<AbstractViewController>>{}, this)
                 }
  );
}

void ChatRoomMenuView::TextChanged(TextField &sender, const std::string &old_text) {
}

void ChatRoomMenuView::TextEditingFinished(TextField &sender) {
//  sender.SetInnerText("This TextField has been altered");
}