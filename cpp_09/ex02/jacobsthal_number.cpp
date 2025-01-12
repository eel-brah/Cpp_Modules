

#include <cmath>
#include <cstdlib>
#include <iostream>
long jacobsthal_number(long n) {
  return round((pow(2, n + 1) + pow(-1, n)) / 3);
}
int main (int argc, char *argv[]) {
  
  std::cout << jacobsthal_number(atoi(argv[1])) << std::endl;
  std::cout << jacobsthal_number(atoi(argv[1]) ) - jacobsthal_number(atoi(argv[1]) - 1) << std::endl;
  return 0;
}
