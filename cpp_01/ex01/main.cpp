#include "Zombie.hpp"

int main()
{
	int count = 10;
	Zombie *zombies = zombieHorde(count, "Boo");
	if (!zombies)
		return 1;
	for(int i = 0; i < count; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}