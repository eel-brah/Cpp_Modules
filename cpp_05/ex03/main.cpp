#include "Bureaucrat.hpp"
#include "Intern.hpp"

void test(int c) {
  switch (c) {
  case 1:
    std::cout << "Test 1: \n";
    try {
      Intern someRandomIntern;
      AForm *rrf;
      rrf = someRandomIntern.makeForm("robotomy request", "Bender");
      if (!rrf)
        return;
      Bureaucrat b("Bob", 2);
      std::cout << b;
      rrf->beSigned(b);
      rrf->execute(b);
      delete rrf;
    } catch (MyException &e) {
      std::cout << e.what();
    }
    break;
  case 2:
    std::cout << "Test 2: \n";
    try {
      Intern someRandomIntern;
      AForm *rrf;
      rrf = someRandomIntern.makeForm("nonexest form", "Bender");
      if (!rrf)
        return;
      Bureaucrat b("Bob", 2);
      std::cout << b;
      rrf->beSigned(b);
      rrf->execute(b);
      delete rrf;
    } catch (MyException &e) {
      std::cout << e.what();
    }
    break;
  }
}
int main() {
  test(1);
  test(2);
}
