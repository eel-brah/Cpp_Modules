#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "<Derived> \033[0;36mWrongCat created!\033[0m" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << "<Derived> \033[0;36mDestructor for WrongCat called\033[0m" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << "<Derived> \033[0;36mWrongCat has been copied!\033[0m" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << "<Derived> \033[0;36mWrongCat's copy assignment operator has been called!\033[0m" << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "\033[0;35mmeow meow!\033[0m" << std::endl;
}