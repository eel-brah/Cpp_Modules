#include "header.hpp"

class Contact {
private:
  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string phone_number;
  std::string darkest_secret;

  std::string getting_input(std::string getting); 
  void formating(std::string str);

public:
  bool fill_contact(); 
  void print_a_contact(); 
  void print_row(unsigned short i);
};
