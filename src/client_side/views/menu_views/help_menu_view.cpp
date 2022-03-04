#include <memory>
#include "help_menu_view.h"
#include "views/label.h"
#include "views/text_field.h"

HelpMenuView::HelpMenuView() : AbstractMenuView(menu_name_) {
  UpdateSubviews({
    std::make_shared<Label>(this,"                       "),
    std::make_shared<Label>(this, "Quoridor is played on a game board of 81 square spaces (9x9). Each player is represented"),
    std::make_shared<Label>(this, "by a pawn which begins at the center space of one edge of the board (in a two-player game,"),
    std::make_shared<Label>(this, "the pawns begin opposite each other). The objective is to be the first player to move their"),
    std::make_shared<Label>(this, "pawn to any space on the opposite side of the game board from which it begins. The distin-"),
    std::make_shared<Label>(this, "guishing characteristic of Quoridor is its twenty walls. Walls are flat two-space-wide"),
    std::make_shared<Label>(this, "pieces which can be placed in the groove that runs between the spaces. Walls block the path"),
    std::make_shared<Label>(this, "of all pawns, which must go around them. The walls are divided equally among the players at"),
    std::make_shared<Label>(this, "the start of the game, and once placed, cannot be moved or removed. On a turn, a player may"),
    std::make_shared<Label>(this, "either move their pawn, or, if possible, place a wall. "),
    std::make_shared<Label>(this,"                       "),
    std::make_shared<Label>(this,"For more details, wikipedia is your best friend https://en.wikipedia.org/wiki/Quoridor"),
    std::make_shared<MenuButtonItem>(this, "Back", std::optional<std::shared_ptr<AbstractViewController>>{}, this)
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
