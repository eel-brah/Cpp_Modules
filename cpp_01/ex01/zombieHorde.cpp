#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
	{
        std::cerr << "Invalid number of Zombies: " << N << std::endl;
        return NULL;
    }

	try
	{
		Zombie* zombies = new Zombie[N]; 
		for(int i = 0; i < N; i++)
			zombies[i].set_name(name);
		return zombies;
    }
	catch (const std::bad_alloc& e)
	{
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }
	return NULL;
}