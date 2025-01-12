#include "Giter.hpp"
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iostream>

#define dequeInt std::deque<unsigned int>
#define dequeIntIter std::deque<unsigned int>::iterator
#define giterDeque Giter<dequeIntIter>

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
    dequeIntIter t = it->iter();
    for (unsigned int i = 0; i < it->iter_size(); i++)
      std::cout << t[i] << " ";
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

template <typename T> bool comp(T a, T b) { return *a < *b; }

void merge_insertion(giterDeque b, giterDeque e) {

  unsigned int size = std::distance(b, e);
  if (size < 2)
    return;

  // is there an unpaired element
  bool odd = size % 2;
  giterDeque end = odd ? e - 1 : e;

  // sort the pairs
  for (giterDeque it = b; it != end; it += 2) {
    if (it[0] > it[1])
      ::swap(it, it + 1);
  }

  // recursively sort the pairs
  merge_insertion(make_pair_iterator(b, 2), make_pair_iterator(end, 2));

  // separate the main and pend chains
  std::deque<giterDeque> main;
  std::deque<giterDeque> pend;

  main.push_back(b);
  main.push_back(b + 1);

  for (giterDeque it = b + 2; it != end; it += 2) {
    main.push_back(it + 1);
    pend.push_back(it);
  }

  if (odd)
    pend.push_back(end);

  // insert pend to main using binary inserion
  long prev = jacobsthal_number(1);
  long curr;
  long diff;
  int inserted = 0;
  int offset;
  int inserions_nbr;
  for (long n = 2;; n++) {
    curr = jacobsthal_number(n);
    diff = curr - prev;
    if (diff > static_cast<long>(pend.size()))
      break;
    offset = 0;
    std::deque<giterDeque>::iterator smain = main.begin() + (curr + inserted);
    std::deque<giterDeque>::iterator it = pend.begin() + (diff - 1);
    inserions_nbr = diff;
    while (inserions_nbr) {
      std::deque<giterDeque>::iterator insertion_pos =
          std::upper_bound(main.begin(), smain, *it, comp<giterDeque>);
      std::deque<giterDeque>::iterator inserted_pos =
          main.insert(insertion_pos, *it);
      it = pend.erase(it);
      it -= 1;
      inserions_nbr--;
      offset += ((inserted_pos - main.begin()) == (curr + inserted));
      smain = main.begin() + (curr + inserted - offset);
    }
    prev = curr;
    inserted += diff;
  }

  // inserting the remaing pend elemet to main - if there is any pend element left 
  for (int i = 0; i < static_cast<int>(pend.size()); i++) {
    std::deque<giterDeque>::iterator curr_pend = pend.begin() + i;
    std::deque<giterDeque>::iterator smain =
        main.begin() + (main.size() - pend.size() + i);

    std::deque<giterDeque>::iterator insertion_pos =
        std::upper_bound(main.begin(), smain, *curr_pend, comp<giterDeque>);
    main.insert(insertion_pos, *curr_pend);
  }

  // copy values to a cache then to origin
  dequeInt cache;
  for (unsigned int i = 0; i < main.size(); i++) {
    dequeIntIter begin = main[i].iter();
    dequeIntIter end = begin + main[i].iter_size();
    cache.insert(cache.end(), begin, end);
    // while (begin != end) {
    //   cache.push_back(*begin);
    //   begin++;
    // }
  }

  dequeIntIter in = b.iter();
  dequeIntIter begin = cache.begin();
  dequeIntIter eend = cache.end();
  std::copy(begin, eend, in);
  // int k = 0;
  // while (begin != eend) {
  //   in[k] = *begin;
  //   begin++;
  //   k++;
  // }
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
  print_deque(b, e);
  return 0;
}
