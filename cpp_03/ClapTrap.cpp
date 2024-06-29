#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name(NULL), hit_points(10), energy_points(10), attack_damage(0) 
{
	std::cout << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << "Constructor for the name " << name << " called" << std::endl;
	try
	{
		this->name = new std::string(name);
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
	attack_damage = 0;
	hit_points = 10;
	energy_points = 10;
}

ClapTrap::~ClapTrap()
{
	if (name)
		std::cout << "Destructor for " << *name << " called" << std::endl;
	else
		std::cout << "Destructor called" << std::endl;
	delete name;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	if (other.name)
	{	
		try
		{
			name = new std::string(*(other.name));
		}
		catch (const std::bad_alloc& e)
		{
			std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		}
	}
	attack_damage = other.attack_damage;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		delete name;
		if (other.name) 
		{
			try
			{
				name = new std::string(*(other.name));
			}
			catch (const std::bad_alloc& e)
			{
				name = NULL;
				std::cerr << "Memory allocation failed: " << e.what() << std::endl;
			}
		}
		else
		{
			name = NULL;
		}
		attack_damage = other.attack_damage;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
	}
	return *this;  
}

void ClapTrap::attack(const std::string& target)
{
	if (!energy_points || !hit_points)
	{
		if(!energy_points)
			std::cout << "\033[0;31mClapTrap " << *name << " is out of energy!\033[0m" << std::endl;
		else
			std::cout << "\033[0;31mClapTrap " << *name << " is out of hit points!\033[0m" << std::endl;
		return;
	}
	energy_points--;
	std::cout << "\033[0;32mClapTrap " << *name << " attacks " << target << ", causing " << attack_damage << " points of damage!\033[0m" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points <= amount)
    {
		if (hit_points == 0)
        	std::cout << "\033[0;31mClapTrap " << *name << " has no hitpoints left!\033[0m" << std::endl;
        else
		{
			std::cout << "\033[0;33mClapTrap " << *name << " takes " << amount-hit_points << " damage and has no hit points left!\033[0m" << std::endl;
			hit_points = 0;
		}
		return;
    }
    hit_points -= amount;
    std::cout << "\033[0;32mClapTrap " << *name << " takes " << amount << " damage, now he has " << hit_points << " hit points left!\033[0m" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	// if (!energy_points || !hit_points)
	if (!energy_points)
	{
		// if (!energy_points)
		std::cout << "\033[0;31mClapTrap " << *name << " is out of energy!\033[0m" << std::endl;
		// else
		// 	std::cout << "\033[0;31mClapTrap " << *name << " is out of hit points!\033[0m" << std::endl;
		return;
	}
	if (hit_points == 10)
	{
		std::cout << "\033[0;33mClapTrap " << *name << " can't be repaired to have more than 10 hit points!\033[0m" << std::endl;
		return;
	}
	if (hit_points + amount > 10)
		amount = 10 - hit_points;
	hit_points += amount;
	energy_points--;
	std::cout << "\033[0;32mClapTrap " << *name << " repairs itself for " << amount << " hit points, now he has " << hit_points << " hit_points and " << energy_points << " energy points!\033[0m" << std::endl;
}
