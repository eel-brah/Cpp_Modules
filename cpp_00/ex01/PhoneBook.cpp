#include <iostream>
#include <cctype>
#include <string>
#include <sstream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

		std::string getting_input(std::string getting)
		{
			std::string tmp;
			std::cout << getting;
			std::getline(std::cin, tmp);
			if (tmp.empty())
			{
				std::cout << "Empty fields are not valid\nTry again: ";
				std::getline(std::cin, tmp);
			}
			return tmp;
		}
	public:
		bool fill_contact()
		{
			first_name = getting_input("First Name: ");
			last_name = getting_input("Last Name: ");
			nickname = getting_input("Nickname: ");
			phone_number = getting_input("Phone Number: ");
			darkest_secret = getting_input("Darkest Secret: ");
			if (first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty())
				return false;
			return true;
		}
		void print_row(unsigned short i)
		{
			std::cout << i << "|" 
						<< first_name << "|" 
						<< last_name << "|" 
						<< nickname << "\n";
		}
		void print_a_contact()
		{
			std::cout << "First Name: " << first_name << "\n"
						<< "Last Name: " << last_name << "\n"
						<< "Nickname: " << nickname << "\n"
						<< "Phone Number: " << phone_number <<"\n"
						<< "Darkest Secret: " << darkest_secret << "\n";
		}
};

class PhoneBook
{
	private:
		Contact contacts[8];
		unsigned short size;
	public:
		void init_phone_book()
		{
			size = 0;
		}
		void add_to_phone_book(Contact contact)
		{
			if (size >= 8)
				size = 0;
			contacts[size] = contact;
			++size;
		}
		void print_phone_book()
		{
			std::cout << "Index" << "|" 
						<< "First Name" << "|" 
						<< "Last Name" << "|"
						<< "Nickname" << "\n";
			for (unsigned short i = 0; i < size; ++i)
				contacts[i].print_row(i);
		}
		void print_a_contact(unsigned short index)
		{
			if (index > size)
				std::cout << "Out of range\n\n";
			else
				contacts[index].print_a_contact();
		}
};

bool is_integer(const std::string& str)
{
    if (str.empty()) return false;

	unsigned int len = str.length();
	unsigned int i = 0;

	if ((str[i] == '-' || str[i] == '+') && len > 1)
        i++;
    for (; i < len; ++i)
	{    
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

// std::cin.clear();
// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

// std::stringstream ss(input);
// int num = 0;
// ss >> num;

int atoi(std::string s)
{
	bool negate = (s[0] == '-');
	int i = 0;
	int len = s.length();
	int result = 0;

	if (s[0] == '+' || s[0] == '-' ) 
		++i;
	while(i < len)
	{
		result = result * 10  - (s[0] - '0');
		++i;
	}
	return negate ? result : -result;
}

int get_int(std::string s)
{
	std::string input;

	while (true)
	{
		std::cout << s;
		std::getline(std::cin, input);
		if (!is_integer(input)) 
			std::cout << "Invalid input. Please enter an integer.\n";
		else
			return atoi(input);
	}
}

int main()
{
	Contact contact;
	PhoneBook phonebook;
	std::string command;

	phonebook.init_phone_book();
	while (true)
	{
		std::cout << "Choose a command ADD, SEARCH or EXIT\nCommand: ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			if (!contact.fill_contact())
			{
				std::cout << "Failed\nReason: empty feild\n\n";
				continue;
			}
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