#include "Bureaucrat.hpp"

void test(int c) {
  switch (c) {
  case 1:
    std::cout << "Test 1: \n";
    try {
      Bureaucrat b("bob", 9);
      std::cout << b;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 2:
    std::cout << "\nTest 2: \n";
    try {
      Bureaucrat b("bob", 0);
      std::cout << b;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 3:
    std::cout << "\nTest 3: \n";
    try {
      Bureaucrat b("bob", 152);
      std::cout << b;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 4:
    std::cout << "\nTest 4: \n";
    try {
      Bureaucrat b("bob", 15);
      std::cout << b;
      b.promotion();
      std::cout << b;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 5:
    std::cout << "\nTest 5: \n";
    try {
      Bureaucrat b("bob", 1);
      std::cout << b;
      b.promotion();
      std::cout << b;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  }
}
int main() {
  test(1);
  test(2);
  test(3);
  test(4);
  test(5);
}
