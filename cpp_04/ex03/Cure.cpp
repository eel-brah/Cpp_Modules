#include "Cure.hpp"

Cure::Cure(): AMateria("ice")
{}

Cure::~Cure()
{}

Cure::Cure(const Cure& other): AMateria(other)
{}

Cure& Cure::operator=(const Cure& other)
{
	// if (this != &other)
	// {
	// 	AMateria::operator=(other);
	// }
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
	std::cout << "* heals " << target.name << "’s wounds *";
}