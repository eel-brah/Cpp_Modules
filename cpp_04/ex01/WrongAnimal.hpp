#ifndef WRONGANIMAL_H_
#define WRONGANIMAL_H_

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		
		void makeSound() const;
		std::string getType() const;
};

#endif