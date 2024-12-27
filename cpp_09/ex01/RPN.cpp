#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &other) { *this = other; }
RPN &RPN::operator=(const RPN &other) {
  if (this != &other)
    this->s = other.s;
  return *this;
}

int RPN::calc(const std::string &exp) {
  std::istringstream stream(exp);
  std::string w;

  while (stream >> w) {
    if (w.length() == 1 && isdigit(w[0])) {
      s.push(w[0] - '0');
    } else {
      if (s.size() < 2)
        throw std::runtime_error("Error");
      int i = s.top();
      s.pop();
      int j = s.top();
      s.pop();
      if (w == "+")
        s.push(j + i);
      else if (w == "-")
        s.push(j - i);
      else if (w == "*")
        s.push(j * i);
      else if (w == "/") {
        if (i == 0)
          throw std::runtime_error("Error: divide by 0");
        s.push(j / i);
      } else
        throw std::runtime_error("Error");
    }
  }

  if (s.size() != 1)
    throw std::runtime_error("Error");
  return s.top();
}
