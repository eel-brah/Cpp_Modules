#include "BitcoinExchange.hpp"
#include <iostream>

#define db "data.csv"

double isValidValue(const std::string line, const std::string &value) {
  char *endptr;
  const char *cvalue;
  double dvalue;

  cvalue = value.c_str();
  errno = 0;
  dvalue = std::strtod(cvalue, &endptr);
  if (endptr == cvalue || *endptr != 0) {
    std::cout << "Error: bad input => " << line << std::endl;
    return -1;
  }
  if (errno == ERANGE || dvalue > 1000) {
    std::cout << "Error: too large a number." << std::endl;
    return -1;
  }
  if (dvalue < 0) {
    std::cout << "Error: not a positive number." << std::endl;
    return -1;
  }
  return dvalue;
}

bool isValidDate(const std::string &date) {
  if (date.size() != 10)
    return false;

  int day, month, year;
  char d1, d2;
  int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  std::istringstream ss(date);
  ss >> year >> d1 >> month >> d2 >> day;

  if (ss.fail() || !ss.eof())
    return false;

  if (d1 != '-' || d2 != '-' || month < 1 || month > 12 || year < 1)
    return false;

  if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
    monthDays[1] = 29;

  if (day < 1 || day > monthDays[month - 1])
    return false;

  return true;
}

bool checkInput(std::string line, std::string *date, double *dvalue) {
  std::string value;

  size_t pos = line.find('|');
  if (pos == std::string::npos ||
      (line[pos + 1] != ' ' || line[pos - 1] != ' ')) {
    std::cout << "Error: bad input => " << line << std::endl;
    return false;
  }
  *date = line.substr(0, pos - 1);
  if (!isValidDate(*date)) {
    std::cout << "Error: bad date => " << *date << std::endl;
    return false;
  }
  value = line.substr(pos + 1);
  *dvalue = isValidValue(line, value);
  if (*dvalue == -1)
    return false;
  return true;
}

int main(int ac, char *av[]) {
  if (ac < 2) {
    std::cout << "Error: could not open file." << std::endl;
    return 1;
  }

  std::string line;
  std::string date;
  double value;
  double price;
  BitcoinExchange *b;

  try {
    b = new BitcoinExchange(db);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  std::ifstream file(av[1]);
  if (!file.is_open()) {
    std::cout << "Error: could not open file." << std::endl;
    delete b;
    return 1;
  }

  std::getline(file, line);
  while (std::getline(file, line)) {
    if (!checkInput(line, &date, &value))
      continue;

    price = b->get_price(date);
    if (price == -1)
      continue;
    std::cout << date << " => " << value << " = " << value * price << std::endl;
  }

  delete b;
  return 0;
}
