#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const char *database) {
  std::ifstream file(database);
  std::string line;
  std::string date;
  std::string price;
  double d;

  if (!file.is_open())
    throw std::runtime_error("Error: could not open database");

  std::getline(file, line);
  while (std::getline(file, line)) {
    size_t comma = line.find(',');
    date = line.substr(0, comma);
    price = line.substr(comma + 1);

    d = std::strtod(price.c_str(), NULL);
    db.insert(std::pair<std::string, double>(date, d));
  }

  file.close();
}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other)
    db = other.db;
  return *this;
}

void BitcoinExchange::print() {
  std::map<std::string, double>::iterator it;
  for (it = db.begin(); it != db.end(); ++it) {
    std::cout << it->first << " => " << it->second << std::endl;
  }
}

double BitcoinExchange::get_price(std::string date) {
  std::map<std::string, double>::iterator it = db.lower_bound(date);
  if (it == db.end()) {
    std::cout << "Error: bad date => " << date << std::endl;
    return -1;
  }
  if (it->first == date)
    return it->second;
  if (it != db.begin()) {
    it--;
    return it->second;
  }
  std::cout << "Error: bad date => " << date << std::endl;
  return -1;
}
