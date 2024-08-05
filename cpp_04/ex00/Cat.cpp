/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:32:24 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:32:24 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "<Derived> \033[0;36mCat created!\033[0m" << std::endl;
}
Cat::~Cat()
{
	std::cout << "<Derived> \033[0;36mDestructor for Cat called\033[0m" << std::endl;
}
Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "<Derived> \033[0;36mCat has been copied!\033[0m" << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "<Derived> \033[0;36mCat's copy assignment operator has been called!\033[0m" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "\033[0;35mmeow meow!\033[0m" << std::endl;
}