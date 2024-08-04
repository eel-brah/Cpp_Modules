#include <cctype>
#include <cstring>
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
  else {
    int len;
    for (int i = 1; i < argc; ++i) {
      len = strlen(argv[i]);
      for (int j = 0; j < len; j++)
        std::cout << (char)toupper(argv[i][j]);
    }
    std::cout << std::endl;
  }
  return 0;
}
