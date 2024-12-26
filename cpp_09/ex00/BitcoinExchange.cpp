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
    // std::stringstream ss(line);
    // std::getline(ss, price, ',');
    // std::getline(ss, date, ',');
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
  // if no date get the closest date
 std::map<std::string, double>::iterator it = db.find(date);
    if (it != db.end()) {
        return it->second;
    } else {
        std::cout << "Key not found!" << std::endl;
    }
  return 0;
}
