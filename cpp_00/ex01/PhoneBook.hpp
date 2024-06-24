#include "header.hpp"
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		unsigned short size;
		unsigned short pos;

		void print_a_contact(unsigned short index)
		{
			if (index >= size)
				std::cout << "Out of range\n";
			else
				contacts[index].print_a_contact();
			std::cout << std::endl;
		}
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
		void phone_book_search()
		{
			std::cout << std::setw(10) << "Index" << "|" 
						<< std::setw(10) << "First Name" << "|" 
						<< std::setw(10) << "Last Name" << "|"
						<< std::setw(10) << "Nickname" << std::endl;
			// std::cout << "----------------------------------------------" << std::endl;
			for (unsigned short i = 0; i < size; ++i)
				contacts[i].print_row(i);
			print_a_contact(get_int("Choose an index (from 0 to 7): "));
		}
};
