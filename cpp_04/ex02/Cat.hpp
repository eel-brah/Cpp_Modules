#ifndef CAT_H_
#define CAT_H_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		
		void makeSound() const;
		void add_idea(const std::string& idea);
		std::string get_idea(const unsigned int i);
};

#endif