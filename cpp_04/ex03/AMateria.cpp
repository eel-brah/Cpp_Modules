/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:35:57 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:35:57 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria(): type("None") {}

AMateria::AMateria(std::string const & type): type(type) {}

AMateria::AMateria(const AMateria& other): type(other.type) {}

AMateria::~AMateria(){}

AMateria& AMateria::operator=(const AMateria& other)
{
	(void) other;
	return *this;
}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* A materia used on " << target.getName() << " *" << std::endl;
}