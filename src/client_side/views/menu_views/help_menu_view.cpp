#include <memory>
#include "help_menu_view.h"
#include "views/label.h"
#include "views/text_field.h"

HelpMenuView::HelpMenuView() : AbstractMenuView(menu_name_) {
  UpdateSubviews({
    std::make_shared<Label>(this,"                       "),
    std::make_shared<Label>(this, "Quoridor is played on a game board of 81 square spaces (9x9)."),
    std::make_shared<Label>(this, "Each player is represented by a pawn which begins at the center space of one edge of the board"),
    std::make_shared<Label>(this,"(in a two-player game, the pawns begin opposite each other)."),
    std::make_shared<Label>(this,"The objective is to be the first player to move their pawn to any space on the opposite side of the game board from which it begins."),
    std::make_shared<Label>(this, "The distinguishing characteristic of Quoridor is its twenty walls. "),
    std::make_shared<Label>(this, "Walls are flat two-space-wide pieces which can be placed in the groove that runs between the spaces."),
    std::make_shared<Label>(this, "Walls block the path of all pawns, which must go around them. "),
    std::make_shared<Label>(this, "The walls are divided equally among the players at the start of the game, and once placed, cannot be moved or removed. "),
    std::make_shared<Label>(this, "On a turn, a player may either move their pawn, or, if possible, place a wall. "),
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
