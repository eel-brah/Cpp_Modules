#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}
void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::harlFilter( std::string level )
{
	Ptrs ptrs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int i = 0;
	for (; i < UNKNOWN; ++i)
	{
		if (level == levels[i])
			break ;
	}

	switch (i)
	{
		case DEBUG:
			std::cout << "[ " << levels[0] << " ]\n";
			(this->*ptrs[DEBUG])();
			// Fall through
		case INFO:
			std::cout << "[ " << levels[1] << " ]\n";
			(this->*ptrs[INFO])();
			// Fall through
		case WARNING:
			std::cout << "[ " << levels[2] << " ]\n";
			(this->*ptrs[WARNING])();
			// Fall through
		case ERROR:
			std::cout << "[ " << levels[3] << " ]\n";
			(this->*ptrs[ERROR])();
			break;
		default:
			std::cout <<"[ Probably complaining about insignificant problems ]\n";
	}
}