#include "Contact.hpp"

class PhoneBook {
private:
  Contact contacts[8];
  unsigned short size;
  unsigned short pos;

  void print_a_contact(unsigned short index);
public:
  PhoneBook();
  void add_to_phone_book(Contact contact); 
  void phone_book_search(); 
};
