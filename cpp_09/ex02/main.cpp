#include "Giter.hpp"
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iostream>

#define dequeInt std::deque<unsigned int>
#define dequeIntIter std::deque<unsigned int>::iterator

long jacobsthal_number(long n) {
  return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

template <typename Iter> void print_deque(Giter<Iter> b, Giter<Iter> e) {
  Iter begin = b.iter();
  Iter end = e.iter();
  for (Iter it = begin; it != end; it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}
template <typename Iter> void print_deque_iter(std::deque<Iter> b) {
  for (typename std::deque<Iter>::iterator it = b.begin(); it != b.end();
       ++it) {
    std::cout << *it->iter() << " ";
  }
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

// template <typename iter> unsigned int distance(iter b, iter e) {
//   // unsigned int size = 0;
//   // while (b != e) {
//   //   ++b;
//   //   ++size;
//   // }
//   return b - e;
// }

template <typename T> bool comp(T a, T b) { return *a < *b; }

template <typename iter> void merge_insertion(iter b, iter e) {

  unsigned int size = std::distance(b, e);
  std::cout << "Size: " << size << std::endl;
  if (size < 2)
    return;
  // is there an unpaired element
  bool odd = size % 2;
  iter end = odd ? e - 1 : e;
  // sort the pairs
  for (iter it = b; it != end; it += 2) {
    std::cout << it[0] << " " << it[1] << "\n";
    if (it[0] > it[1])
      ::swap(it, it + 1);
  }
  print_deque(b, e);

  // recursively sort the pairs
  merge_insertion(make_pair_iterator(b, 2), make_pair_iterator(end, 2));

  std::cout << "=============\n";
  // separate the main and pend chains
  std::deque<iter> main;
  std::deque<iter> pend;

  main.push_back(b);
  main.push_back(b + 1);

  for (iter it = b + 2; it != end; it += 2) {
    main.push_back(it + 1);
    pend.push_back(it);
  }

  if (odd)
    pend.push_back(end);
  // std::cout << "main: ";
  // print_deque_iter(main);
  //
  // std::cout << "pend: ";
  // print_deque_iter(pend);
  //
  long prev = jacobsthal_number(1);
  long curr;
  long diff;
  int inserted = 0;
  int offset = 0; 
  for (long n = 2;; n++) {
    curr = jacobsthal_number(n);
    diff = curr - prev;
    if (diff > pend.size())
      break;
    typename std::deque<iter>::iterator it = pend.begin();
    typename std::deque<iter>::iterator bound =
        main.begin() + (curr + inserted);
    it += diff;
    int inserions_nbr = diff;
    while (inserions_nbr) {
      typename std::deque<iter>::iterator insertion_pos =
          std::upper_bound(main.begin(), bound, *it, comp<iter>);
      typename std::deque<iter>::iterator inserted_pos =
          main.insert(insertion_pos, *it);
      it = pend.erase(it);
      it -= 1;
      offset += (inserted_pos - main.begin()) == curr + inserted;
      bound = main.begin() + (curr + inserted - offset);
    }
    prev = curr;
    inserted += diff;
    offset = 0;
  }
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
  Giter<dequeIntIter> e(c1.end(), 1);

  merge_insertion(b, e);
  return 0;
}
