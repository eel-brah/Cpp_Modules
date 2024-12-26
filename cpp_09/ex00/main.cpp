#include "BitcoinExchange.hpp"
#include <iostream>

#define db "data.csv"

int main(int ac, char *av[]) {
  if (ac < 2) {
    std::cout << "Error: could not open file." << std::endl;
    return 1;
  }
    BitcoinExchange b(db);
  try {
    BitcoinExchange bb(db);
    b = bb;
    // b.print();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  std::ifstream file(av[1]);
  if (!file.is_open()) {
    std::cout << "Error: could not open file." << std::endl;
    return 1;
  }

  std::string line;
  std::string date;
  std::string value;
  const char *cvalue;
  double dvalue;
  char *endptr;

  std::getline(file, line);
  while (std::getline(file, line)) {
    size_t pos = line.find('|');
    if (pos == std::string::npos) {
      std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }
    date = line.substr(0, pos);
    // check date
    value = line.substr(pos + 1);
    cvalue = value.c_str();
    errno = 0;
    dvalue = std::strtod(cvalue, &endptr);
    if (endptr == cvalue || *endptr != 0) {
      std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }
    if (errno == ERANGE || dvalue > 1000) {
      std::cout << "Error: too large a number." << std::endl;
      continue;
    }
    if (dvalue < 0) {
      std::cout << "Error: not a positive number." << std::endl;
      continue;
    }

    double price = b.get_price(date);
    std::cout << date << " => " << dvalue << " = " << dvalue*price << std::endl;
  }

  return 0;
}
