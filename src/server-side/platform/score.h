//
// Created by Anton Romanova on 10/12/2021.
//

#ifndef QUORIDOR_SERVER_SIDE_PLATFORM_SCORE_H_
#define QUORIDOR_SERVER_SIDE_PLATFORM_SCORE_H_

class Score {

 public:
  [[nodiscard]] unsigned int GetValue() const {
    return score_value_;
  }

  void SetValue(long score_value_change) {
    if (score_value_change < 0) {
      if (score_value_ >= -score_value_change){
        score_value_ += score_value_change;
      } else {
        score_value_ = 0;
      }
    } else if (score_value_change > ULONG_LONG_MAX - score_value_) {
      // TODO: Overflow error, shouldn't happen. If it does, we screwed something elsewhere. Maybe if it happens, LOG the error as CRITICAL and kill the process?
      exit(1);
    } else {
      score_value_ += score_value_change;
    }
  }

 private:
  unsigned long score_value_;
};

#endif //QUORIDOR_SERVER_SIDE_PLATFORM_SCORE_H_
