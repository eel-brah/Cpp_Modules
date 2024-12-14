#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
  srand(static_cast<unsigned int>(time(0)));
  int random_number = rand() % 3;

  switch (random_number) {
  case 0:
    return new A();
  case 1:
    return new B();
  default:
    return new C();
  }
}

void identify(Base *p) {
  std::cout << "Identify by pointer: ";

  if (dynamic_cast<A *>(p))
    std::cout << "Class A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "Class B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "Class C" << std::endl;
}

void identify(Base &p) {
  std::cout << "Identify by reference: ";

  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "Class A" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "Class B" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "Class C" << std::endl;
  } catch (std::exception &e) {
  }
}

int main() {
  Base *ptr = generate();
  Base &ref = *ptr;

  identify(ptr);
  identify(ref);

  delete ptr;
  return 0;
}
