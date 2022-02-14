//
// Created by guest on 14/02/2022.
//

#include "SelectionMenuView.h"
void SelectionMenuView ::Display(std::vector<bool> toselect ) const {
  mv->settoSelect(toselect);
  mv->Display();
}