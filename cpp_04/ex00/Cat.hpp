#ifndef CAT_H_
#define CAT_H_

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		
		void makeSound() const;
};

#endif