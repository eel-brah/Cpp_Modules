/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:30:38 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:30:38 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// ClapTrap::ClapTrap(): name("Bob"), hit_points(10), energy_points(10), attack_damage(0) 
// {
// 	std::cout << "Default constructor called" << std::endl;
// }
// ClapTrap::ClapTrap(const std::string& name): name(name), hit_points(10), energy_points(10), attack_damage(0) 
// {
// 	std::cout << "Param Constructor for the name " << name << " called" << std::endl;
// }

ClapTrap::ClapTrap(): name("Bob"), hit_points(10), energy_points(10), attack_damage(0) 
{
	std::cout << "\033[0;36mA ClapTrap " << name << " created!\033[0m" << std::endl;
}
ClapTrap::ClapTrap(const std::string& name): name(name), hit_points(10), energy_points(10), attack_damage(0) 
{
	std::cout << "\033[0;36mClapTrap " << name << " created!\033[0m" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[0;36mDestructor for ClapTrap " << name << " called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "\033[0;36mClapTrap " << name << " has been copied!\033[0m" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		name = other.name;
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
			std::cout << "\033[0;31mClapTrap " << name << " is out of energy!\033[0m" << std::endl;
		else
			std::cout << "\033[0;31mClapTrap " << name << " is out of hit points!\033[0m" << std::endl;
		return;
	}
	energy_points--;
	std::cout << "\033[0;32mClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!\033[0m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points <= amount)
    {
		if (hit_points == 0)
        	std::cout << "\033[0;31mClapTrap " << name << " has no hit points left!\033[0m" << std::endl;
        else
		{
			// std::cout << "\033[0;33mClapTrap " << name << " takes " << hit_points << " damage and has no hit points left!\033[0m" << std::endl;
			std::cout << "\033[0;33mClapTrap " << name << " takes " << amount << " damage and has no hit points left!\033[0m" << std::endl;
			hit_points = 0;
		}
		return;
    }
    hit_points -= amount;
    std::cout << "\033[0;32mClapTrap " << name << " takes " << amount << " damage, now he has " << hit_points << " hit points left!\033[0m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!energy_points)
	{
		std::cout << "\033[0;31mClapTrap " << name << " is out of energy!\033[0m" << std::endl;
		return;
	}
	hit_points += amount;
	energy_points--;
	std::cout << "\033[0;32mClapTrap " << name << " repairs itself for " << amount << " hit points, now he has " << hit_points << " hit_points and " << energy_points << " energy points!\033[0m" << std::endl;
}
