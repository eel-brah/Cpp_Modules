#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " Level\n";
		return 1;
	}
	Harl harl;
	harl.harlFilter(std::string(argv[1]));
}