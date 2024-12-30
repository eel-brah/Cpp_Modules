#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test(int c) {
  switch (c) {
  case 1:
    std::cout << "Test 1: \n";
    try {
      ShrubberyCreationForm s("target");
      Bureaucrat b("Bob", 12);
      std::cout << b;
      std::cout << s;
      s.beSigned(b);
      s.execute(b);
      std::cout << s;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 2:
    std::cout << "Test 2: \n";
    try {
      ShrubberyCreationForm s("target");
      Bureaucrat b("Bob", 12);
      std::cout << b;
      s.execute(b);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
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
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 4:
    std::cout << "Test 4: \n";
    try {
      RobotomyRequestForm r("target");
      Bureaucrat b("Bob", 12);
      std::cout << b;
      r.beSigned(b);
      r.execute(b);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 5:
    std::cout << "Test 5: \n";
    try {
      RobotomyRequestForm r("target");
      Bureaucrat b("Bob", 12);
      std::cout << b;
      r.execute(b);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 6:
    std::cout << "Test 6: \n";
    try {
      RobotomyRequestForm r("target");
      Bureaucrat b("Bob", 150);
      std::cout << b;
      r.beSigned(b);
      r.execute(b);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 7:
    std::cout << "Test 7: \n";
    try {
      PresidentialPardonForm p("target");
      Bureaucrat b("Bob", 2);
      std::cout << b;
      p.beSigned(b);
      p.execute(b);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 8:
    std::cout << "Test 8: \n";
    try {
      PresidentialPardonForm p("target");
      Bureaucrat b("Bob", 22);
      std::cout << b;
      b.signForm(p);
      p.execute(b);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 9:
    std::cout << "Test 9: \n";
    try {
      PresidentialPardonForm p("target");
      Bureaucrat b("Bob", 5);
      std::cout << b;
      std::cout << p;
      b.signForm(p);
      b.executeForm(p);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    break;
  case 10:
    std::cout << "Test 10: \n";
    try {
      PresidentialPardonForm p("target");
      Bureaucrat b("Bob", 5);
      std::cout << b;
      std::cout << p;
      // b.signForm(p);
      b.executeForm(p);
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
  test(4);
  test(5);
  test(6);
  test(7);
  test(8);
  test(9);
  test(10);
}
