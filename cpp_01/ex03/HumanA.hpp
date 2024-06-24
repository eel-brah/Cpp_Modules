#ifndef HUMANA_H_
#define HUMANA_H_

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		void attack();
};

#endif