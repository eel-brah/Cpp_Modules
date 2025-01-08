#include <cerrno>
#include <climits>
#include <cstdlib>
#include <deque>
#include <iostream>

int main(int ac, char *av[]) {
  if (ac < 2) {
    std::cout << "Invalid input" << std::endl;
    return 1;
  }
  std::deque<unsigned int> c1;

  av++;
  while (*av) {
    char *r = NULL;
    long i = strtol(*av, &r, 10);
    if (r == *av || *r ||
        ((i == LONG_MAX || i == LONG_MIN) && errno == ERANGE) || i > UINT_MAX ||
        i < 0) {
      std::cout << "Invalid input" << std::endl;
      return 1;
    }
    c1.push_back(static_cast<unsigned int>(i));
    av++;
  }

  if (c1.size() < 2) {
    std::cout << "Sorted" << std::endl;
    return 0;
  }
  bool odd = c1.size() % 2;

  std::deque<unsigned int>::iterator end = odd ? c1.end() - 1 : c1.end();
  for (std::deque<unsigned int>::iterator it = c1.begin(); it != end; it += 2) {
    if (it[0] < it[1]) 
      iter_swap(it, it + 1);
  }
  for (std::deque<unsigned int>::iterator it = c1.begin(); it != c1.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  return 0;
}
