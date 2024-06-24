#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string& name) : name(name){}
		~Zombie();

		void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif