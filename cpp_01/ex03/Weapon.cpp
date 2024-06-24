#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	setType(weapon);
}

const std::string& Weapon::getType()
{
	return _weapon;
}
void Weapon::setType(std::string weapon)
{
	_weapon = weapon;
}