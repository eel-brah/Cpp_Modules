#include "Span.hpp"

Span::Span() : size(0) {}
Span::Span(unsigned int n) : size(n) {}
Span::~Span() {}
Span::Span(const Span &other) { *this = other; }
Span &Span::operator=(const Span &other) {
  if (this != &other) {
    // v.clear();
    // v.insert(v.begin(), other.v.begin(), other.v.end());
    v = other.v;
    size = other.size;
  }
  return *this;
}

void Span::addNumber(int nbr) {
  if (v.size() >= size)
    throw std::runtime_error("The container is full");
  v.push_back(nbr);
}

// template <typename Iterator>
// void Span::addNumbers(Iterator begin, Iterator end) {
//   for (Iterator it = begin; it != end; ++it) {
//     addNumber(*it);
//   }
// }

int Span::shortestSpan() {
  std::vector<int> tmpV;
  int shortest;
  int span;

  if (v.size() < 2)
    throw std::runtime_error("Not enough numbers");

  tmpV = v;
  std::sort(tmpV.begin(), tmpV.end());

  shortest = tmpV[1] - tmpV[0];
  for (size_t i = 2; i < tmpV.size(); i++) {
    span = tmpV[i] - tmpV[i - 1];
    if (shortest > span)
      shortest = span;
  }
  return shortest;
}

int Span::longestSpan() {
  std::vector<int> tmpV;

  if (v.size() < 2)
    throw std::runtime_error("Not enough numbers");

  tmpV = v;
  std::sort(tmpV.begin(), tmpV.end());

  return tmpV[tmpV.size() - 1] - tmpV[0];
}
