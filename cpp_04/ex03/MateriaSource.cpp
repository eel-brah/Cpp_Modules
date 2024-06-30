#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): size(0)
{}
MateriaSource::MateriaSource(const MateriaSource& other)
{
	size = 0;
	try
	{
		for (int i = 0; i < other.size; i++)
		{
			if (other.mantras[i]->getType() == "ice")
				mantras[i] = new Ice();
			else
				mantras[i] = new Cure();
			size++;
		}
	}
	catch (const std::bad_alloc& e)
	{
		for (int i = 0; i < size; i++)
			delete mantras[i];
		size = 0;
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < size; i++)
		delete mantras[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		int i;
		for (i = 0; i < size; i++)
			delete mantras[i];
		size = 0;
		try
		{
			for (i = 0; i < other.size; i++)
			{
				if (other.mantras[i]->getType() == "ice")
					mantras[i] = new Ice();
				else
					mantras[i] = new Cure();
				size++;
			}
		}
		catch (const std::bad_alloc& e)
		{
			for (i = 0; i < size; i++)
				delete mantras[i];
			size = 0;
			std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (size < SIZE_MAX)
		mantras[size] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < size; i++)
	{
		if (mantras[i]->getType() == type)
			return mantras[i];
	}
	return NULL;
}