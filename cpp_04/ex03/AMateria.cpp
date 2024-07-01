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