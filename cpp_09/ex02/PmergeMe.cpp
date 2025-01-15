#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  (void)other;
  return *this;
}

void PmergeMe::merge_insertion_vec(giterVec b, giterVec e) {

  unsigned int size = std::distance(b, e);
  if (size < 2)
    return;

  // is there an unpaired element
  bool odd = size % 2;
  giterVec end = odd ? e - 1 : e;

  // sort the pairs
  for (giterVec it = b; it != end; it += 2) {
    if (it[0] > it[1])
      gswap(it, it + 1);
  }

  // recursively sort the pairs
  merge_insertion_vec(make_pair_iterator(b, 2), make_pair_iterator(end, 2));

  // separate the main and pend chains
  std::vector<giterVec> main;
  std::vector<giterVec> pend;
  pend.reserve(size / 2 - 1 + odd * 1);
  main.reserve(size);

  main.push_back(b);
  main.push_back(b + 1);

  for (giterVec it = b + 2; it != end; it += 2) {
    main.push_back(it + 1);
    pend.push_back(it);
  }

  if (odd)
    pend.push_back(end);

  // insert pend to main using binary inserion using jacobsthal numbers
  long prev = jacobsthal_number(1);
  long curr;
  long diff;
  int inserted = 0;
  int offset;
  int inserions_nbr;
  for (int n = 2;; n++) {
    curr = jacobsthal_number(n);
    diff = curr - prev;
    if (diff > static_cast<long>(pend.size()))
      break;
    offset = 0;
    std::vector<giterVec>::iterator smain = main.begin() + (curr + inserted);
    std::vector<giterVec>::iterator it = pend.begin() + (diff - 1);
    inserions_nbr = diff;
    while (inserions_nbr) {
      std::vector<giterVec>::iterator insertion_pos =
          std::upper_bound(main.begin(), smain, *it, comp<giterVec>);
      std::vector<giterVec>::iterator inserted_pos =
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

  // inserting the remaing pend elemet to main - if there is any pend element
  // left
  for (int i = 0; i < static_cast<int>(pend.size()); i++) {
    std::vector<giterVec>::iterator curr_pend = pend.begin() + i;
    std::vector<giterVec>::iterator smain =
        main.begin() + (main.size() - pend.size() + i + 1);

    std::vector<giterVec>::iterator insertion_pos =
        std::upper_bound(main.begin(), smain, *curr_pend, comp<giterVec>);
    main.insert(insertion_pos, *curr_pend);
  }

  // copy values to a cache then to origin
  vecInt cache;
  cache.reserve(size);
  for (unsigned int i = 0; i < main.size(); i++) {
    vecIntIter begin = main[i].iter();
    vecIntIter end = begin + main[i].iter_size();
    cache.insert(cache.end(), begin, end);
  }

  vecIntIter in = b.iter();
  vecIntIter begin = cache.begin();
  vecIntIter eend = cache.end();
  std::copy(begin, eend, in);
}
void PmergeMe::merge_insertion_deque(giterDeque b, giterDeque e) {

  unsigned int size = std::distance(b, e);
  if (size < 2)
    return;

  // is there an unpaired element
  bool odd = size % 2;
  giterDeque end = odd ? e - 1 : e;

  // sort the pairs
  for (giterDeque it = b; it != end; it += 2) {
    if (it[0] > it[1])
      gswap(it, it + 1);
  }

  // recursively sort the pairs
  merge_insertion_deque(make_pair_iterator(b, 2), make_pair_iterator(end, 2));

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

  // insert pend to main using binary inserion using jacobsthal numbers
  long prev = jacobsthal_number(1);
  long curr;
  long diff;
  int inserted = 0;
  int offset;
  int inserions_nbr;
  for (int n = 2;; n++) {
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

  // inserting the remaing pend elemet to main - if there is any pend element
  // left
  for (int i = 0; i < static_cast<int>(pend.size()); i++) {
    std::deque<giterDeque>::iterator curr_pend = pend.begin() + i;
    std::deque<giterDeque>::iterator smain =
        main.begin() + (main.size() - pend.size() + i + 1);

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
  }

  dequeIntIter in = b.iter();
  dequeIntIter begin = cache.begin();
  dequeIntIter eend = cache.end();
  std::copy(begin, eend, in);
}

long PmergeMe::jacobsthal_number(unsigned int n) {
  return round((pow(2, n + 1) + pow(-1, n)) / 3);
}
