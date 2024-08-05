/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:35:06 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:35:06 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << "<Base> \033[0;36mAn Animal created!\033[0m" << std::endl;
}
Animal::Animal(std::string type): type(type)
{
	std::cout << "<Base> \033[0;36mThe Animal [" << type << "] created!\033[0m" << std::endl;
}
Animal::~Animal()
{
	std::cout << "<Base> \033[0;36mDestructor for Animal " << type << " called\033[0m" << std::endl;
}
Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "<Base> \033[0;36mAnimal " << type << " has been copied!\033[0m" << std::endl;
}
Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "<Base> \033[0;36mAnimal's copy assignment operator has been called!\033[0m" << std::endl;
	return *this;
}

std::string Animal::getType() const
{
	return type;
}