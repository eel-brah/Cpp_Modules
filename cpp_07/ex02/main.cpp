#include "Array.hpp"

void test(int i) {
  if (i == 1) {
    std::cout << "Empty test\n";
    Array<int> emp;
    std::cout << "Size: " << emp.size() << std::endl;
    return;
  }
  if (i == 2) {
    std::cout << "Int test\n";
    Array<int> arr(7);
    std::cout << "Size of arr: " << arr.size() << std::endl;

    for (unsigned int i = 0; i < arr.size(); i++)
      arr[i] = i + 2;

    std::cout << "Init arr2 with arr\n";
    Array<int> arr2(arr);
    std::cout << "Size of arr2: " << arr2.size() << std::endl;

    arr2[0] = 5;
    std::cout << "arr2[0]: " << arr2[0] << std::endl;
    std::cout << "arr[0]: " << arr[0] << std::endl;
    return;
  }
  if (i == 3) {
    std::cout << "Float test\n";
    Array<float> arr(7);
    std::cout << "Size: " << arr.size() << std::endl;

    for (unsigned int i = 0; i < arr.size(); i++)
      arr[i] = i * 1.1;

    std::cout << "Init arr2 with arr\n";
    Array<float> arr2 = arr;
    std::cout << "Size: " << arr2.size() << std::endl;

    arr2[0] = 5.5;
    std::cout << "arr2[0]: " << arr2[0] << std::endl;
    std::cout << "arr[0]: " << arr[0] << std::endl;
    return;
  }
  if (i == 4) {
    std::cout << "String test\n";
    Array<std::string> arr(3);
    std::cout << "Size: " << arr.size() << std::endl;

    for (unsigned int i = 0; i < arr.size(); i++)
      arr[i] = "Hi";

    std::cout << "Init arr2 with arr\n";
    Array<std::string> arr2 = arr;
    std::cout << "Size: " << arr2.size() << std::endl;

    arr2[0] = "Hello";
    std::cout << "arr2[0]: " << arr2[0] << std::endl;
    std::cout << "arr[0]: " << arr[0] << std::endl;
    return;
  }
  if (i == 5) {
    std::cout << "Out of range test\n";
    Array<int> arr(4);
    std::cout << "Size: " << arr.size() << std::endl;

    try {
      arr[9] = 9;
    } catch (const std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
    return;
  }
}

int main() {
  test(1);
  std::cout << std::endl;
  test(2);
  std::cout << std::endl;
  test(3);
  std::cout << std::endl;
  test(4);
  std::cout << std::endl;
  test(5);
}
