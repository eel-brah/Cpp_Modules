#include "AMateria.hpp"

AMateria::AMateria(): type("None") {}

AMateria::AMateria(std::string const & type): type(type) {}

AMateria::AMateria(const AMateria& other): type(other.type)
{
	// *this = other;
}

AMateria::~AMateria(){}

AMateria& AMateria::operator=(const AMateria& other)
{
	// if (this != &other)
	// {
	// 	type = other.type;
	// }
	return *this;
}

std::string const & AMateria::getType() const
{
	return type;
}
