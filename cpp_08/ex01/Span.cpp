#include "Span.hpp"

Span::Span() : size(0) {}
Span::Span(unsigned int n) : size(n) {}
Span::~Span() {}
Span::Span(const Span &other) { *this = other; }
Span &Span::operator=(const Span &other) {
  if (this != &other) {
    span.clear();
    span.insert(span.begin(), other.span.begin(), other.span.end());
    size = other.size;
  }
  return *this;
}

void Span::addNumber(int nbr){
  if (span.size() >= size)
    throw std::runtime_error("The container is full");
  // span.insert(nbr);
}
