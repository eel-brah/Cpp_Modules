#include "header.hpp"

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

int atoi(const std::string& str)
{
	bool negate = !(str[0] == '-');
	int i = 0;
	int len = str.length();
	int result = 0;

	if (str[0] == '+' || str[0] == '-' ) ++i;
	while(i < len)
		result = result * 10  + (str[i++] - '0');
	return negate ? result : -result;
}

int get_int(const std::string& str)
{
	std::string input;

	while (true)
	{
		std::cout << str;
		std::getline(std::cin, input);
		if (!is_integer(input)) 
			std::cout << "Invalid input. Please enter an integer.\n";
		else
			return atoi(input);
	}
}