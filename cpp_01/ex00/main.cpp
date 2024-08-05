#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
	randomChump("FOOO");

	Zombie *zombie = newZombie("Boo");
	if (!zombie)
		return 1;
	zombie->announce();
	delete zombie;
}