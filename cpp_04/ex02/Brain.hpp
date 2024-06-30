#ifndef BRAIN_H_
#define BRAIN_H_

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		
		void add_idea(const std::string& idea);
		std::string get_idea(const unsigned int i);
};

#endif