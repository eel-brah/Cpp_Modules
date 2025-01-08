#include "Giter.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <deque>
#include <iostream>

#define dequeInt std::deque<unsigned int>
#define dequeIntIter std::deque<unsigned int>::iterator

void print_deque(Giter<dequeIntIter> b, Giter<dequeIntIter> e) {
  dequeIntIter begin = b.iter();
  dequeIntIter end = e.iter();
  for (dequeIntIter it =begin; it != end; it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}

bool fill_deque(dequeInt &c, char **args) {
  char *r;
  long i;

  while (*args) {
    r = NULL;
    i = strtol(*args, &r, 10);
    // TODO: long or int
    if (*r || ((i == LONG_MAX || i == LONG_MIN) && errno == ERANGE) ||
        i > UINT_MAX || i < 0) {
      std::cout << "Invalid inputs" << std::endl;
      return false;
    }
    c.push_back(static_cast<unsigned int>(i));
    args++;
  }
  return true;
}

template <typename iter> unsigned int distance(iter b, iter e) {
  // unsigned int size = 0;
  // while (b != e) {
  //   ++b;
  //   ++size;
  // }
  return b - e;
}

template <typename iter> void merge_insertion(iter b, iter e) {

  // sort each pari in a descending order
  unsigned int size = distance(b, e);
  bool odd = size % 2;
  iter end = odd ? e - 1 : e;
  for (iter it = b; it != end; it += 2) {
    if (it[0] < it[1])
      iter_swap(it, it + 1);
  }
  print_deque(b, e);

  // sort the paits in an ascending order based on the top one
  // print_deque(c1);
}

int main(int ac, char *av[]) {
  if (ac < 2) {
    std::cout << "Invalid inputs" << std::endl;
    return 1;
  }

  dequeInt c1;

  // add numbers to a deque
  fill_deque(c1, av + 1);
  if (c1.size() < 2) {
    // TODO:
    std::cout << "Sorted" << std::endl;
    return 1;
  }

  Giter<dequeIntIter> b(c1.begin(), 1);
  Giter<dequeIntIter> e(c1.end() - 1, 1);

  merge_insertion(b, e);
  return 0;
}
