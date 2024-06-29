#ifndef DIAMONDTRAP_H_
#define DIAMONDTRAP_H_

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string name;
		// unsigned int hit_points;
		// unsigned int energy_points;
		// unsigned int attack_damage;
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
		
		void attack(const std::string& target);
		void whoAmI();
};

#endif