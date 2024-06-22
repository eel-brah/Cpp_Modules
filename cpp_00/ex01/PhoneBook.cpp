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
		// if (std::cin.eof())
		// {
		// 	std::cin.clear();
		// 	std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		// 	continue;
		// }
		// if (std::cin.fail() || std::cin.bad())
		if (command == "ADD")
		{
			if (!contact.fill_contact())
			{
				std::cout << "Failed\nReason: empty feild\n\n";
				continue;
			}
			else
				std::cout << "Done\n\n";
			phonebook.add_to_phone_book(contact);
		}
		else if (command == "SEARCH")
		{
			phonebook.print_phone_book();
			phonebook.print_a_contact(get_int("Choose an index (from 0 to 7): "));
		}
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
