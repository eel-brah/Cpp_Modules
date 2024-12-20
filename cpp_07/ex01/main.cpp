#include "iter.h"
#include <iostream>

template <typename T> void func(T a) { std::cout << a << std::endl; }

int main() {
  int arr1[10];
  float arr2[10];

  for (int i = 1; i <= 10; i++)
       arr1[i-1] = i;
  for (int i = 1; i <= 10; i++)
       arr2[i-1] = i * 1.1f;

  std::cout << "Test 1: int array\n";
  iter(arr1, 10, func<int>);

  std::cout << "\nTest 2: float array\n";
  iter(arr2, 10, func<float>);

  std::string s[4] = {"AAA", "BBBB", "CC", "DDD"};
  std::cout << "\nTest 3: string array\n";
  iter(s, 4, func<std::string>);
}
