#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::string s = "hi there hi bob";
	std::size_t found = s.find("hi", 99);
	if (std::string::npos == found)
	{
		std::cout << "NONe\n";
		return 1;
	}
}