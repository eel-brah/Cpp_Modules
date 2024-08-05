/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:35:38 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:35:38 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
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
	std::cout << "<Derived> \033[0;36mDog created!\033[0m" << std::endl;
}
Dog::~Dog()
{
	delete brain;
	std::cout << "<Derived> \033[0;36mDestructor for Dog called\033[0m" << std::endl;
}
Dog::Dog(const Dog& other): Animal(other)
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
	std::cout << "<Derived> \033[0;36mDog has been copied!\033[0m" << std::endl;
}
Dog& Dog::operator=(const Dog& other)
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
	std::cout << "<Derived> \033[0;36mDog's copy assignment operator has been called!\033[0m" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "\033[0;35mwoof woof!\033[0m" << std::endl;
}

void Dog::add_idea(const std::string& idea)
{
	brain->add_idea(idea);
}

std::string Dog::get_idea(const unsigned int i)
{
	return brain->get_idea(i);
}