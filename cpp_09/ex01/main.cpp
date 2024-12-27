#include "RPN.hpp"

int main(int ac, char *av[]) {

  if (ac != 2) {
    std::cout << "Error: invalid number of args" << std::endl;
    return 1;
  }
  try {
    RPN r;
   std::cout << r.calc(av[1]) << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
