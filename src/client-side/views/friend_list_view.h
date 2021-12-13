//
// Created by Anton Romanova on 11/12/2021.
//

#ifndef QUORIDOR_CLIENT_SIDE_VIEWS_FRIEND_LIST_VIEW_H_
#define QUORIDOR_CLIENT_SIDE_VIEWS_FRIEND_LIST_VIEW_H_

#include "auto_refreshing_view.h"

class FriendListView: AutoRefreshingView {
 private:
  void OpenChatRoom();
  void PrintFriendList();
  void AddFriend();
  void RemoveFriend();
};

#endif //QUORIDOR_CLIENT_SIDE_VIEWS_FRIEND_LIST_VIEW_H_
