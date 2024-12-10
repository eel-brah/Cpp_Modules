#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

void test(int c) {
  switch (c) {
  case 1:
    std::cout << "Test 1: \n";
    try {
      ShrubberyCreationForm s("target");
      Bureaucrat b("Bob", 12);
      std::cout << b;
      s.beSigned(b);
      s.execute(b);
    } catch (MyException &e) {
      std::cout << e.what();
    }
    break;
  case 2:
    std::cout << "Test 2: \n";
    try {
      ShrubberyCreationForm s("target");
      Bureaucrat b("Bob", 12);
      std::cout << b;
      s.execute(b);
    } catch (MyException &e) {
      std::cout << e.what();
    }
    break;
  case 3:
    std::cout << "Test 3: \n";
    try {
      ShrubberyCreationForm s("target");
      Bureaucrat b("Bob", 150);
      std::cout << b;
      s.beSigned(b);
      s.execute(b);
    } catch (MyException &e) {
      std::cout << e.what();
    }
    break;
  case 4:
    std::cout << "\nTest 4: \n";
    try {
      ShrubberyCreationForm s("target");
      Bureaucrat b("Bob", 150);
      std::cout << s;
      std::cout << b;
      s.beSigned(b);
    } catch (MyException &e) {
      std::cout << e.what();
    }
    break;
  case 5:
    std::cout << "\nTest 5: \n";
    try {
      ShrubberyCreationForm s("target");
      Bureaucrat b("Bob", 150);
      std::cout << s;
      std::cout << b;
      b.signForm(s);
    } catch (MyException &e) {
      std::cout << e.what();
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
