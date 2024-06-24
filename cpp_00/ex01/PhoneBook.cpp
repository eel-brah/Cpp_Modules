#include "PhoneBook.hpp"
#include "header.hpp"

int main()
{
	Contact contact;
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		std::cout << "Choose a command ADD, SEARCH or EXIT\nCommand: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			command = "EXIT";
		// if (std::cin.fail() || std::cin.bad())
		if (command == "ADD")
		{
			if (!contact.fill_contact())
			{
				std::cout << "Failed\nReason: empty feild(s)\n\n";
				continue;
			}
			phonebook.add_to_phone_book(contact);
			std::cout << "Done\n\n";
		}
		else if (command == "SEARCH")
			phonebook.phone_book_search();
		else if (command == "EXIT")
		{
			std::cout << "Exitting...\n";
			break;
		}
		else
			std::cout << "Invalid command\n\n";
	}
	return 0;
}
