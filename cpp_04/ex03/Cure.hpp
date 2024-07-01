#ifndef CURE_H_
#define CURE_H_

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif