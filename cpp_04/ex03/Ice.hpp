#ifndef ICE_H_
#define ICE_H_

#include "AMateria.hpp"

class Ice: public AMateria
{
	private:
		
	public:
		Ice();
		// Ice(std::string const& type);
		~Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif