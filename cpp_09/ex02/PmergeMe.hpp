#ifndef PMERGEME_H_
#define PMERGEME_H_

#include "Giter.hpp"
#include <cmath>
#include <deque>
#include <vector>

#define dequeInt std::deque<unsigned int>
#define dequeIntIter std::deque<unsigned int>::iterator
#define giterDeque Giter<dequeIntIter>
#define vecInt std::vector<unsigned int>
#define vecIntIter std::vector<unsigned int>::iterator
#define giterVec Giter<vecIntIter>

class PmergeMe {
private:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);

  static long jacobsthal_number(unsigned int n);
  template <typename T> static bool comp(T a, T b) { return *a < *b; }

public:
  static void merge_insertion_deque(giterDeque b, giterDeque e);
  static void merge_insertion_vec(giterVec b, giterVec e);
};
#endif
