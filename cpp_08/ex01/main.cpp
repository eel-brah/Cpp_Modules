#include "Span.hpp"
#include <climits>
#include <iostream>
#include <vector>

void fillvector(std::vector<int> &vec, size_t size, int min = 0,
                int max = INT_MAX) {
  srand(static_cast<unsigned int>(time(0)));
  vec.resize(size);
  for (size_t i = 0; i < size; ++i)
    vec[i] = rand() % (max - min + 1) + min;
}

void test(int i) {
  switch (i) {
  case 1: {
    std::cout << "Test1:\n";
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    break;
  }
  case 2: {
    std::cout << "\nTest2:\n";
    Span sp(5);
    sp.addNumber(4);
    try {
      std::cout << sp.shortestSpan() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  }
  case 3: {
    std::cout << "\nTest3:\n";
    Span sp(1);
    try {
      sp.addNumber(4);
      sp.addNumber(8);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  }
  case 4: {
    std::cout << "\nTest4:\n";
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    Span sp2(sp);
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    break;
  }
  case 5: {
    std::cout << "\nTest5:\n";
    Span sp(10000);

    std::vector<int> v;
    fillvector(v, 10000);
    sp.addNumbers(v.begin(), v.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    break;
  }
  case 6: {
    std::cout << "\nTest6:\n";
    Span sp(1000000);

    std::vector<int> v;
    fillvector(v, 1000000);
    sp.addNumbers(v.begin(), v.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    break;
  }
  }
}

int main() {
  test(1);
  test(2);
  test(3);
  test(4);
  test(5);
  test(6);
  return 0;
}
