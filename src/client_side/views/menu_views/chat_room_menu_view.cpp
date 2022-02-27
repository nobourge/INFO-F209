#include "views/label.h"
#include "views/text_field.h"
#include "chat_room_menu_view.h"
#include <memory>


ChatRoomMenuView::ChatRoomMenuView() : AbstractMenuView(menu_name_) {
  UpdateSubviews({
                     std::make_shared<Label>(this, msg1),
                     std::make_shared<Label>(this, msg2),
                     std::make_shared<Label>(this, msg3),
                     std::make_shared<TextField>(this, "Text:", this),
                     std::make_shared<MenuButtonItem>(this, "Back", std::optional<std::shared_ptr<AbstractViewController>>{}, this)
                 }
  );
}

void ChatRoomMenuView::TextChanged(TextField &sender, const std::string &old_text) {
}

void ChatRoomMenuView::MessageChanged(std::string new_message) {
  msg3=msg2;
  msg2=msg1;
  msg1=new_message;
}

void ChatRoomMenuView::TextEditingFinished(TextField &sender) {
  MessageChanged(sender.GetInnerText().substr(5,sender.GetInnerText().size()));
  UpdateSubviews({
                     std::make_shared<Label>(this, msg1),
                     std::make_shared<Label>(this, msg2),
                     std::make_shared<Label>(this, msg3),
                     std::make_shared<TextField>(this, "Text:", this),
                     std::make_shared<MenuButtonItem>(this, "Back", std::optional<std::shared_ptr<AbstractViewController>>{}, this)
                 }
  );
}