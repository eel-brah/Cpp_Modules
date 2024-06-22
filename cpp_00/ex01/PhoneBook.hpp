#include "header.hpp"
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		unsigned short size;
		unsigned short pos;
	public:
		PhoneBook()
		{
			size = 0;
			pos = 0;
		}
		void add_to_phone_book(Contact contact)
		{
			if (size < 8)
				size++;
			if (pos >= 8)
				pos = 0;
			contacts[pos++] = contact;
		}
		void print_phone_book()
		{
			std::cout << std::setw(10) << "Index" << "|" 
						<< std::setw(10) << "First Name" << "|" 
						<< std::setw(10) << "Last Name" << "|"
						<< std::setw(10) << "Nickname" << std::endl;
			// std::cout << "----------------------------------------------" << std::endl;
			for (unsigned short i = 0; i < size; ++i)
				contacts[i].print_row(i);
		}
		void print_a_contact(unsigned short index)
		{
			if (index >= size)
				std::cout << "Out of range\n\n";
			else
				contacts[index].print_a_contact();
		}
};
