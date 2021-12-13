//
// Created by Anton Romanova on 11/12/2021.
//

#ifndef QUORIDOR_CLIENT_SIDE_VIEWS_ACCOUNT_DELETION_MENU_H_
#define QUORIDOR_CLIENT_SIDE_VIEWS_ACCOUNT_DELETION_MENU_H_

#include "auto_refreshing_view.h"
#include <memory>

struct AccountDeletionViewDelegate {
  virtual void DeleteAccount() = 0;
};

class AccountDeletionView: AutoRefreshingView {
 private:
  void DeleteButtonPushed() {
    if (!delegate_.expired()) {
      delegate_.lock()->DeleteAccount();
    }
  }
  std::weak_ptr<AccountDeletionViewDelegate> delegate_;
};

#endif //QUORIDOR_CLIENT_SIDE_VIEWS_ACCOUNT_DELETION_MENU_H_
