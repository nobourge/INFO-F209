#ifndef BOARDFETCHER_H
#define BOARDFETCHER_H
#include <QThread>
#include "../../models/api_wrapper.h"

class BoardFetcher : public QThread {
    Q_OBJECT
    int game_id;
    bool oneMoreTime;
public:
    BoardFetcher(QObject* parent, int game_id, std::weak_ptr<bool> should_continue_fetching);
    void run();
    std::weak_ptr<bool> should_continue_fetching_;
signals:
    void updated();
};

#endif