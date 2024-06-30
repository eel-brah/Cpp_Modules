#ifndef DOG_H_
#define DOG_H_

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);

		void makeSound() const;
};

#endif