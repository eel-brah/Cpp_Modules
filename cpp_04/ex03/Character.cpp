#include "Character.hpp"

Character::Character(): name("Unkown"), inv_size(0)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		equipted[i] = 0;
		inventory[i] = NULL;
	}
}

Character::Character(std::string const& name): name(name), inv_size(0)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		equipted[i] = 0;
		inventory[i] = NULL;
	}
}

Character::Character(const Character& other)
{
	name = other.name;
	// inv_size = 0;
	try
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			if (other.equipted[i] && other.inventory[i]->getType() == "ice")
			{
				inventory[i] = new Ice();
				equipted[i] = other.equipted[i];
			}
			else if (other.equipted[i] && other.inventory[i]->getType() == "cure")
			{
				inventory[i] = new Cure();
				equipted[i] = other.equipted[i];
			}
			// inv_size++;
		}
	}
	catch (const std::bad_alloc& e)
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			equipted[i] = 0;
			delete inventory[i];
			inventory[i] = NULL;
		}
		// inv_size = 0;
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
}

Character::~Character()
{
	for (int i = 0; i < MAX_SIZE; i++)
		delete inventory[i];
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		name = other.name;
		int i;
		for (i = 0; i < inv_size; i++)
		{
			equipted[i] = 0;
			delete inventory[i];
			inventory[i] = NULL;
		}
		// inv_size = 0;
		try
		{
			for (i = 0; i < MAX_SIZE; i++)
			{
				if (other.equipted[i] && other.inventory[i]->getType() == "ice")
				{
					inventory[i] = new Ice();
					equipted[i] = other.equipted[i];
				}
				else if (other.equipted[i] && other.inventory[i]->getType() == "cure")
				{
					inventory[i] = new Cure();
					equipted[i] = other.equipted[i];
				}
				// inv_size++;
			}
		}
		catch (const std::bad_alloc& e)
		{
			for (i = 0; i < MAX_SIZE; i++)
			{
				equipted[i] = 0;
				delete inventory[i];
				inventory[i] = NULL;
			}
			// inv_size = 0;
			std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < MAX_SIZE; i++)
		if (!equipted[i])
		{
			free(inventory[i]);
			inventory[i] = m;
		}
}

void Character::unequip(int idx)
{
	if (idx < MAX_SIZE)
		equipted[idx] = 0; 
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < MAX_SIZE && equipted[idx])
		inventory[idx]->use(target);
}