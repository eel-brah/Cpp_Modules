#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{}

HumanB::~HumanB()
{
	delete _weapon;
}

void HumanB::setWeapon(Weapon& weapon)
{
	try
	{
		_weapon = new Weapon(weapon);
	}
	catch(const std::exception& e)
	{
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
}

void HumanB::attack()
{
	if (_weapon != NULL)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " can't attack" << std::endl;
}