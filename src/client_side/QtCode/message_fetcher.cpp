//
// Created by Anton Romanova on 31/03/2022.
//

#include "message_fetcher.h"
void MessageFetcher::StartFetching(
    const UserClient &other_user,
    const function<bool()> &should_continue_fetching) {

  while (should_continue_fetching()) {
    auto messages =
        ApiWrapper::GetShared()->GetConversationWithUser(other_user);
    if (std::holds_alternative<std::vector<Message>>(messages)) {
      emit messagesFetched(std::get<std::vector<Message>>(messages),
                           other_user);
    }
    this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}
