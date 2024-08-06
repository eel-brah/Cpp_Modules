/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:31:21 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:31:21 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(std::string("bob")+"_clap_name"), name("Bob")
{
	this->hit_points = 100;
	this->attack_damage = 30;
	this->energy_points = 50;
	// 	this->hit_points = FragTrap::hit_points;
	// this->attack_damage = FragTrap::attack_damage;
	// this->energy_points = ScavTrap::energy_points;
	std::cout << "\033[0;36mA DiamondTrap " << name << " created!\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name+"_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
	this->hit_points = 100;
	this->attack_damage = 30;
	this->energy_points = 50;
	// this->hit_points = FragTrap::hit_points;
	// this->attack_damage = FragTrap::attack_damage;
	// this->energy_points = ScavTrap::energy_points;
	std::cout << "\033[0;36mDiamondTrap " << name << " created!\033[0m" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[0;36mDestructor for DiamondTrap " << name << " called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	// *this = other;
	this->name = other.name;
	std::cout << "\033[0;36mDiamondTrap " << this->name << " has been copied!\033[0m" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
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

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "\033[0;35mMy name is " << this->name << ", ClapTrap is " << ClapTrap::name << "\033[0m" << std::endl;
}