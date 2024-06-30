#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\033[0;36m==>> Brain created!\033[0m" << std::endl;
}
Brain::~Brain()
{
	std::cout << "\033[0;36m==>> Destructor for Brain called\033[0m" << std::endl;
}
Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "\033[0;36m==>> Brain has been copied!\033[0m" << std::endl;
}
Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	std::cout << "\033[0;36m==>> Brain's copy assignment operator has been called!\033[0m" << std::endl;
	return *this;
}

void Brain::add_idea(const std::string& idea)
{
	static unsigned int i;

	ideas[i%100] = idea;
	i++;
}

std::string Brain::get_idea(const unsigned int i)
{
	return ideas[i%100];
}