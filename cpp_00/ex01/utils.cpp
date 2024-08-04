#include "header.hpp"

std::string int_to_string(int num) {
  std::stringstream ss;
  ss << num;
  return ss.str();
}

std::string trim(const std::string &str, std::string set) {
  std::string trimmed = str;

  std::string::size_type start = trimmed.find_first_not_of(set);
  if (start != std::string::npos)
    trimmed = trimmed.substr(start);
  else {
    trimmed.clear();
    return trimmed;
  }

  std::string::size_type end = trimmed.find_last_not_of(set);
  if (end != std::string::npos)
    trimmed = trimmed.substr(0, end + 1);
  else
    trimmed.clear();

  return trimmed;
}

void replace_tabs_with_spaces(std::string &str) {
  for (std::string::size_type i = 0; i < str.length(); i++) {
    if (str[i] == '\t')
      str[i] = ' ';
  }
}

std::string formating(std::string str) {
  replace_tabs_with_spaces(str);
  if (str.length() > 10) {
    str.resize(9);
    str.push_back('.');
  } else {
    for (std::string::size_type i = str.length(); i < 10; i++)
      str = ' ' + str;
  }
  return str;
}
