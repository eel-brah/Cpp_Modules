#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string& name);
		~Zombie();

		void announce( void );
};

#endif