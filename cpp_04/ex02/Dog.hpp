#ifndef DOG_H_
#define DOG_H_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);

		void makeSound() const;
		void add_idea(const std::string& idea);
		std::string get_idea(const unsigned int i);
};

#endif