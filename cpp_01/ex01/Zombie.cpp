#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
	std::cout << "Destroying: " << name << std::endl;
}

void Zombie::set_name(std::string& name)
{
	this->name = name;
}