#include "Cure.hpp"
#include "Character.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure& other): AMateria(other) {}

Cure& Cure::operator=(const Cure& other)
{
	(void) other;
	return *this;
}

AMateria* Cure::clone() const
{
	AMateria* cure_clone = NULL;
	try
	{
		cure_clone = new Cure();
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
	return cure_clone;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}