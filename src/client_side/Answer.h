//
// Created by guest on 12/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_ANSWER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_ANSWER_H_

#endif //QUORIDOR_SRC_CLIENT_SIDE_ANSWER_H_
#include <string>
#include <vector>
using namespace std;
class Answer{
  string key;

 public:
  Answer(){
  }
  virtual operator string(){
  }
  virtual operator vector<bool>(){
  }
};
class AnswerString:public Answer{
  string answer;
    public:
    AnswerString(){
    }
    operator string(){
      return answer;
    }
};
class AnswerBool:public Answer{
  vector<bool> answer;
 public:
  AnswerBool(){
  }
  operator vector<bool>(){
    return answer;
  }
};
