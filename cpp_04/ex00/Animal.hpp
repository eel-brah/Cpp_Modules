#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		
		virtual void makeSound() const;
		std::string getType() const;
};

#endif