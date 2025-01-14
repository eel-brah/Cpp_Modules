/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:50:18 by eel-brah          #+#    #+#             */
/*   Updated: 2025/01/14 13:27:26 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>

bool check_input(char **args) {
  char *r;
  long i;

  while (*args) {
    r = NULL;
    errno = 0;
    i = strtol(*args, &r, 10);
    if (*r || ((i == LONG_MAX || i == LONG_MIN) && errno == ERANGE) ||
        i > UINT_MAX || i < 0) {
      return false;
    }
    args++;
  }
  return true;
}

void fill_deque(dequeInt &c, char **args) {
  long i;

  while (*args) {
    i = strtol(*args, NULL, 10);
    c.push_back(static_cast<unsigned int>(i));
    args++;
  }
}

void fill_vec(vecInt &c, int ac, char **args) {
  long i;
  c.reserve(ac);

  while (*args) {
    i = strtol(*args, NULL, 10);
    c.push_back(static_cast<unsigned int>(i));
    args++;
  }
}

void print_input(char **args) {
  while (*args)
    std::cout << *args++ << " ";
  std::cout << std::endl;
}

void print_vector(vecInt vec) {
  vecIntIter b = vec.begin();
  vecIntIter e = vec.end();
  while (b != e)
    std::cout << *b++ << " ";
  std::cout << std::endl;
}

int main(int ac, char *av[]) {
  if (ac < 2 || !check_input(av + 1)) {
    std::cerr << "Invalid input" << std::endl;
    return 1;
  }

  int number_of_args = ac - 1;
  clock_t start;
  clock_t end;

  // deque
  start = clock();
  dequeInt c1;
  fill_deque(c1, av + 1);
  Giter<dequeIntIter> b1(c1.begin(), 1);
  Giter<dequeIntIter> e1(c1.end(), 1);
  PmergeMe::merge_insertion_deque(b1, e1);
  end = clock();
  double duration1 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

  // vector
  start = clock();
  vecInt c2;
  fill_vec(c2, number_of_args, av + 1);
  Giter<vecIntIter> b2(c2.begin(), 1);
  Giter<vecIntIter> e2(c2.end(), 1);
  PmergeMe::merge_insertion_vec(b2, e2);
  end = clock();
  double duration2 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

  std::cout << "Before: ";
  print_input(av + 1);
  std::cout << "After:  ";
  print_vector(c2);
  std::cout << "Time to process a range of " << number_of_args
            << " elements with std::deque : " << duration1 << " ms"
            << std::endl;
  std::cout << "Time to process a range of " << number_of_args
            << " elements with std::vector : " << duration2 << " ms"
            << std::endl;
  return 0;
}
