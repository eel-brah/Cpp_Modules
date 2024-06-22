#include "header.hpp"

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
			tmp = trim(tmp, " \t\r\v\n\f");
			if (tmp.empty())
			{
				std::cout << "Empty fields are not valid\nTry again: ";
				std::getline(std::cin, tmp);
				tmp = trim(tmp, " \t\r\v\n\f");
			}
			return tmp;
		}
		void formating(std::string str)
		{
			const short Width = 10;
			replace_tabs_with_spaces(str);
			if (str.length() > Width)
				std::cout << std::setw(Width) << str.substr(0, Width - 1) << ".";
			else
				std::cout << std::setw(Width) << str;
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
			formating(int_to_string(i));
			std::cout << "|";
			formating(first_name);
			std::cout << "|";
			formating(last_name);
			std::cout << "|";
			formating(nickname);
			std::cout << std::endl;
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