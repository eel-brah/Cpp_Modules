#include "Bureaucrat.hpp"
#include "Form.hpp"

void test(int c) {
  switch (c) {
  case 1:
    std::cout << "Test 1: \n";
    try {
      Form f("FormA", 9, 9);
      std::cout << f;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 2:
    std::cout << "\nTest 2: \n";
    try {
      Form f("FormA", 990, 9);
      std::cout << f;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 3:
    std::cout << "\nTest 3: \n";
    try {
      Form f("FormB", 9, 9);
      Bureaucrat b("Bob", 2);
      std::cout << f;
      std::cout << b;
      f.beSigned(b);
      std::cout << f;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 4:
    std::cout << "\nTest 4: \n";
    try {
      Form f("FormC", 1, 1);
      Bureaucrat b("Bob", 2);
      std::cout << f;
      std::cout << b;
      f.beSigned(b);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 5:
    std::cout << "\nTest 5: \n";
    try {
      Form f("FormC", 5, 5);
      Bureaucrat b("Bob", 2);
      std::cout << f;
      std::cout << b;
      b.signForm(f);
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
