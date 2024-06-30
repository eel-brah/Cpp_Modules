#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <cstring>

class Character
{
	private:
		std::string name;
		static const unsigned short MAX_SIZE = 4;
		AMateria *inventory[MAX_SIZE];
		bool equipted[4];
		unsigned short inv_size;
	public:
		Character();
		Character(std::string const& name);
		Character(const Character& other);
		~Character();
		Character& operator=(const Character& other);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif