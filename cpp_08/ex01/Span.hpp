#ifndef SPAN_H_
#define SPAN_H_

#include <algorithm>
#include <stdexcept>
#include <vector>

class Span {
private:
  std::vector<int> v;
  unsigned int size;

public:
  Span();
  Span(unsigned int n);
  ~Span();
  Span(const Span &other);
  Span &operator=(const Span &other);

  void addNumber(int nbr);
  int shortestSpan();
  int longestSpan();
  template <typename Iterator> void addNumbers(Iterator begin, Iterator end) {
    for (Iterator it = begin; it != end; ++it) {
      addNumber(*it);
    }
  }
};

#endif
