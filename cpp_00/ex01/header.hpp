#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>

// std::string formating(std::string str);
std::string int_to_string(int num);

int get_int(const std::string& s);
std::string trim(const std::string& str, std::string set);
void replace_tabs_with_spaces(std::string& str);

#endif