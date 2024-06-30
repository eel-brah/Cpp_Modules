#ifndef CURE_H_
#define CURE_H_

#include "AMateria.hpp"

class Cure: public AMateria
{
	private:
		
	public:
		Cure();
		// Cure(std::string const& type);
		~Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif