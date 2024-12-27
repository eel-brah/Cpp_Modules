#ifndef RPN_H_
#define RPN_H_

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <stack>

class RPN {
private:
  std::stack<int> s;

public:
  RPN();
  ~RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);

  int calc(const std::string &exp);
};
#endif
