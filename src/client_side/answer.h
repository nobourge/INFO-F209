#ifndef QUORIDOR_SRC_CLIENT_SIDE_ANSWER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_ANSWER_H_

#endif //QUORIDOR_SRC_CLIENT_SIDE_ANSWER_H_
#include <string>
#include <vector>
using namespace std;

class AbstractAnswer{
  string key;

 public:
  AbstractAnswer(){
  }
  virtual operator string(){
  }
  virtual operator vector<bool>(){
  }
};

template <typename T>
class Answer : public AbstractAnswer{
  T answer;
 public:
  Answer(T answer) : answer(answer) {}
  operator T() { return answer; }
};
