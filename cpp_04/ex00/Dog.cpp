#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "<Derived> \033[0;36mDog created!\033[0m" << std::endl;
}
Dog::~Dog()
{
	std::cout << "<Derived> \033[0;36mDestructor for Dog called\033[0m" << std::endl;
}
Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << "<Derived> \033[0;36mDog has been copied!\033[0m" << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "<Derived> \033[0;36mDog's copy assignment operator has been called!\033[0m" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "\033[0;35mwoof woof!\033[0m" << std::endl;
}