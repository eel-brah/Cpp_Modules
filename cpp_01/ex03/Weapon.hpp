#ifndef WEAPON_H_
#define WEAPON_H_

#include <iostream>

class Weapon
{
	private:
		std::string _weapon;
	public:
		Weapon(std::string weapon);
		const std::string& getType();
		void setType(std::string weapon);
};

#endif