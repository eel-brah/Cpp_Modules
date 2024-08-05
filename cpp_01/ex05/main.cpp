#include "Harl.hpp"

void test1()
{
	Harl harl;
	std::string str = "ERROR";
	harl.complain(str);
}
void test2()
{
	Harl harl;
	std::string str = "Invalid";
	harl.complain(str);
}
void test3()
{
	Harl harl;
	std::string str = "WARNING";
	harl.complain(str);
}

int main()
{
	test1();
	// test2();
	// test3();
}