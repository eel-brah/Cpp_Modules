/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:31:46 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:31:46 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "\033[0;36mA ScavTrap " << name << " created!\033[0m" << std::endl;
	this->hit_points = 100;
	this->attack_damage = 20;
	this->energy_points = 50;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
	std::cout << "\033[0;36mScavTrap " << name << " created!\033[0m" << std::endl;
	this->hit_points = 100;
	this->attack_damage = 20;
	this->energy_points = 50;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[0;36mDestructor for ScavTrap " << this->name << " called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	// *this = other;
	std::cout << "\033[0;36mScavTrap " << this->name << " has been copied!\033[0m" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
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

void ScavTrap::attack(const std::string& target)
{
	if (!this->energy_points || !this->hit_points)
	{
		if(!this->energy_points)
			std::cout << "\033[0;31mScavTrap " << this->name << " is out of energy!\033[0m" << std::endl;
		else
			std::cout << "\033[0;31mScavTrap " << this->name << " is out of hit points!\033[0m" << std::endl;
		return;
	}
	(this->energy_points)--;
	std::cout << "\033[0;32mScavTrap " << this->name << " attacks " << target << ", causing " << attack_damage << " points of damage!\033[0m" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "\033[0;35mScavTrap " << this->name << " is now in Gatekeeper mode!\033[0m" << std::endl;
}