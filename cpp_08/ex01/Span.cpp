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
  if (v.size() < 2)
    throw std::runtime_error("Not enough numbers");

  int max = *std::max_element(v.begin(), v.end());
  int min = *std::min_element(v.begin(), v.end());
  return max - min;
}
