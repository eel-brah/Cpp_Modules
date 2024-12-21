#include "easyfind.hpp"
#include <deque>
#include <exception>
#include <iostream>
#include <list>
#include <vector>

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
  try {
    std::vector<int>::iterator it = easyfind(v, 3);
    std::cout << "Value found: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::vector<int>::iterator it = easyfind(v, 9);
    std::cout << "Value found: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::list<int> l;
  l.push_back(2);
  l.push_back(10);
  l.push_back(30);
  l.push_back(9);
  try {
    std::list<int>::iterator it = easyfind(l, 10);
    std::cout << "Value found: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::deque<int> d;
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  try {
    std::deque<int>::iterator it = easyfind(d, 10);
    std::cout << "Value found: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::deque<int>::iterator it = easyfind(d, 2);
    std::cout << "Value found: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
