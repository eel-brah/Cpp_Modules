#include "header.hpp"

bool is_int(const std::string &str) {
  if (str.empty())
    return false;

  unsigned int len = str.length();
  unsigned int i = 0;

  if ((str[i] == '-' || str[i] == '+') && len > 1)
    i++;
  for (; i < len; ++i) {
    if (!std::isdigit(str[i]))
      return false;
  }
  return true;
}

int atoi(const std::string &str, bool *of) {
  bool negate = !(str[0] == '-');
  int i = 0;
  int len = str.length();
  int result = 0;
  int tmp;

  if (str[0] == '+' || str[0] == '-')
    ++i;
  while (i < len && std::isdigit(str[i])) {
    tmp = result * 10 + (str[i++] - '0');
    if (result > tmp) {
      *of = true;
      return -1;
    }
    result = tmp;
  }
  return negate ? result : -result;
}

int get_int(const std::string &str) {
  std::string input;
  bool of;

  while (true) {
    std::cout << str;
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      std::cout << std::endl;
      exit(0);
    }
    if (!is_int(input))
      std::cout << "Invalid input. Please enter an integer.\n";
    else
      return atoi(input, &of);
  }
}
