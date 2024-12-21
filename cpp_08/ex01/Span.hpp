#ifndef SPAN_H_
#define SPAN_H_

#include <stdexcept>
#include <vector>

class Span {
private:
  std::vector<int> span;
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
};

#endif
