#include "Ice.hpp"
#include "Character.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& other): AMateria(other) {}

Ice& Ice::operator=(const Ice& other)
{
	(void) other;
	return *this;
}

AMateria* Ice::clone() const
{
	AMateria* ice_clone = NULL;
	try
	{
		ice_clone = new Ice();
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
	return ice_clone;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}