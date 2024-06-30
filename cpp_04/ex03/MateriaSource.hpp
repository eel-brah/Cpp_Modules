#ifndef MATERIASOURCE_H_
#define MATERIASOURCE_H_

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource
{
	private:
		static const unsigned short MAX_SIZE = 4;
		AMateria *mantras[MAX_SIZE];
		unsigned short size;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		~MateriaSource();
		MateriaSource& operator=(const MateriaSource& other);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif