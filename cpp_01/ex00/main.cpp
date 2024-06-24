#include "Zombie.hpp"

int main()
{
	randomChump("FOOO");

	Zombie *zombie = newZombie("Boo");
	if (!zombie)
		return 1;
	zombie->announce();
	delete zombie;
}