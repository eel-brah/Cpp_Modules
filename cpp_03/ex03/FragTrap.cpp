#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "\033[0;36mA FragTrap " << name << " created!\033[0m" << std::endl;
	this->hit_points = 100;
	this->attack_damage = 30;
	this->energy_points = 100;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	std::cout << "\033[0;36mFragTrap " << name << " created!\033[0m" << std::endl;
	this->hit_points = 100;
	this->attack_damage = 30;
	this->energy_points = 100;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[0;36mDestructor for FragTrap " << this->name << " called\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	// *this = other;
	std::cout << "\033[0;36mFragTrap " << this->name << " has been copied!\033[0m" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		// this->name = other.name;
		// this->attack_damage = other.attack_damage;
		// this->hit_points = other.hit_points;
		// this->energy_points = other.energy_points;
	}
	return *this; 
}

void FragTrap::attack(const std::string& target)
{
	if (!this->energy_points || !this->hit_points)
	{
		if(!this->energy_points)
			std::cout << "\033[0;31mFragTrap " << this->name << " is out of energy!\033[0m" << std::endl;
		else
			std::cout << "\033[0;31mFragTrap " << this->name << " is out of hit points!\033[0m" << std::endl;
		return;
	}
	(this->energy_points)--;
	std::cout << "\033[0;32mFragTrap " << this->name << " attacks " << target << ", causing " << attack_damage << " points of damage!\033[0m" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "\033[0;35mFragTrap " << this->name << " is requesting a high fives!\033[0m" << std::endl;
}