#ifndef BITCOINEXCHANGE_H_
#define BITCOINEXCHANGE_H_

#include <map>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

class BitcoinExchange {
private:
  std::map<std::string, double> db;

public:
  BitcoinExchange();
  BitcoinExchange(const char *database);
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);

  void print();
  
  double get_price(std::string date);
};
#endif
