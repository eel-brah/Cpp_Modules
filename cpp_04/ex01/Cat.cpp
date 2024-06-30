#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	try
	{
		brain = new Brain();
	}
	catch (const std::bad_alloc& e)
	{
		brain = NULL;
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
	std::cout << "<Derived> \033[0;36mCat created!\033[0m" << std::endl;
}
Cat::~Cat()
{
	delete brain;
	std::cout << "<Derived> \033[0;36mDestructor for Cat called\033[0m" << std::endl;
}
Cat::Cat(const Cat& other): Animal(other)
{
	if (other.brain)
	{
		try
		{
			brain = new Brain();
			*brain = *(other.brain);
			// brain->operator=(*(other.brain));
		}
		catch (const std::bad_alloc& e)
		{
			brain = NULL;
			std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		}
	}
	else
		brain = NULL;
	std::cout << "<Derived> \033[0;36mCat has been copied!\033[0m" << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		if (other.brain)
		{
			try
			{
				brain = new Brain();
				*brain = *(other.brain);
				// brain->operator=(*(other.brain));
			}
			catch (const std::bad_alloc& e)
			{
				brain = NULL;
				std::cerr << "Memory allocation failed: " << e.what() << std::endl;
			}
		}
		else
			brain = NULL;
	}
	std::cout << "<Derived> \033[0;36mCat's copy assignment operator has been called!\033[0m" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "\033[0;35mmeow meow!\033[0m" << std::endl;
}

void Cat::add_idea(const std::string& idea)
{
	brain->add_idea(idea);
}

std::string Cat::get_idea(const unsigned int i)
{
	return brain->get_idea(i);
}