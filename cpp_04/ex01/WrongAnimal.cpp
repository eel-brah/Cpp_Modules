/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:34:49 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:34:49 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << "<Base> \033[0;36mAn WrongAnimal created!\033[0m" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type): type(type)
{
	std::cout << "<Base> \033[0;36mThe WrongAnimal [" << type << "] created!\033[0m" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "<Base> \033[0;36mDestructor for WrongAnimal " << type << " called\033[0m" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
	std::cout << "<Base> \033[0;36mWrongAnimal " << type << " has been copied!\033[0m" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "<Base> \033[0;36mWrongAnimal's copy assignment operator has been called!\033[0m" << std::endl;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "\033[0;35mSound!\033[0m" << std::endl;
}