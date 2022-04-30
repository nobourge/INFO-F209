//
// Created by Anton Romanova on 31/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_QTCODE_MESSAGE_FETCHER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_QTCODE_MESSAGE_FETCHER_H_

#include "../models/api_wrapper.h"
#include <QtCore/qthread.h>

class MessageFetcher : public QObject {
  Q_OBJECT
public slots:
  void StartFetching(const UserClient &other_user, const std::function<bool()> &should_continue_fetching);
signals:
  void messagesFetched(const std::vector<Message>& messages, const UserClient &other_user);
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_QTCODE_MESSAGE_FETCHER_H_
