#include "Character.hpp"

Character::Character(): name("Unkown")
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		equipted[i] = 0;
		inventory[i] = NULL;
	}
}

Character::Character(std::string const& name): name(name)
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
	for (int i = 0; i < MAX_SIZE; i++)
	{
		equipted[i] = 0;
		inventory[i] = NULL;
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (other.equipted[i])
		{
			inventory[i] = other.inventory[i]->clone();
			if (!inventory[i])
			{
				for (int j = 0; j < MAX_SIZE; j++)
				{
					equipted[j] = 0;
					delete inventory[j];
					inventory[j] = NULL;
				}
			}
			equipted[i] = other.equipted[i];
		}
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
		for (i = 0; i < MAX_SIZE; i++)
		{
			equipted[i] = 0;
			delete inventory[i];
			inventory[i] = NULL;
		}
		for (i = 0; i < MAX_SIZE; i++)
		{
			if (other.equipted[i])
			{
				inventory[i] = other.inventory[i]->clone();
				if (!inventory[i])
				{
					for (int j = 0; j < MAX_SIZE; j++)
					{
						equipted[j] = 0;
						delete inventory[j];
						inventory[j] = NULL;
					}
				}
				equipted[i] = other.equipted[i];
			}
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
	{
		if (inventory[i] == m)
			return;
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (!equipted[i] && m)
		{
			delete inventory[i];
			inventory[i] = m;
			equipted[i] = 1;
			return;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < MAX_SIZE)
		equipted[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < MAX_SIZE && equipted[idx])
		inventory[idx]->use(target);
}