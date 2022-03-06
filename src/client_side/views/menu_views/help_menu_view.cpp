#include <memory>
#include "help_menu_view.h"
#include "views/label.h"
#include "views/text_field.h"

HelpMenuView::HelpMenuView() : AbstractMenuView(menu_name_) {
  UpdateSubviews({
    std::make_shared<Label>(this,"                       "),
    std::make_shared<Label>(this, "Quoridor is a classical board game played by 2 to 4 players on a 9 x 9 board where you can"),
    std::make_shared<Label>(this, "place a wall blocking a path but it cannot stop the player from reaching his goal."),
    std::make_shared<Label>(this, "This version  includes on top of the normal game mode (see further) two new game modes:"),
    std::make_shared<Label>(this, "- Player vs Computer : where a single player plays against an AI"),
    std::make_shared<Label>(this, "- Random wall placement : is a game mode that can be toggled when creating a 1vs1 game"),
    std::make_shared<Label>(this, ",walls are randomly placed on the board"),
    std::make_shared<Label>(this, "- Normal mode : where the player's goal is to reach the the wall at the opposite of their s-"),
    std::make_shared<Label>(this, "pawn location"),
    std::make_shared<Label>(this, ""),
    std::make_shared<Label>(this, "The vertical and horizontal dotted lines reprensent the space between the cells where the"),
    std::make_shared<Label>(this, "walls can be placed. A wall always takes two inter cell space. To place it you have to gi-"),
    std::make_shared<Label>(this, "ve an input in the style of : W->(first cell)->(second cell)->(direction)"),
    std::make_shared<Label>(this, ""),
    std::make_shared<Label>(this, "for example : W->a1->a2-S will place a wall on the cells a1 and a2 to South"),
    std::make_shared<Label>(this, ""),
    std::make_shared<Label>(this, "The hollow space between the dotted lines is a cell from which the player can mo-"),
    std::make_shared<Label>(this, "ve to or move from. To do so you have to give an input in the style of :"),
    std::make_shared<Label>(this, "- if there is nothing where you want to move:"),
    std::make_shared<Label>(this, "M->(direction from the cell where you start)"),
    std::make_shared<Label>(this, "- if there is a player where you want to move and you can hop over:"),
    std::make_shared<Label>(this, "M->(direction from the cell where you start)->(direction from the where you end)"),
    std::make_shared<Label>(this, ""),
    std::make_shared<Label>(this, "For more details, wikipedia is your best friend https://en.wikipedia.org/wiki/Quoridor"),
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
