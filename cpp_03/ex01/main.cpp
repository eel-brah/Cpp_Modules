#include "ScavTrap.hpp"

int main()
{
	std::cout << "<<----- CLAPTRAP ----->>\n" << std::endl;
	ClapTrap clap("Karl");

	clap.attack("Sam");
	clap.takeDamage(4);
	clap.takeDamage(3);
	clap.beRepaired(5);
	clap.takeDamage(10);
	clap.attack("Alice");
	clap.beRepaired(10);
	clap.attack("Alice");
	clap.beRepaired(5);
	for (int i = 0; i < 12; i++)
		clap.attack("Sam");
	clap.beRepaired(3);

	std::cout << "\n\n<<----- SCAVTRAP ----->>\n" << std::endl;
	ScavTrap scav;
	ScavTrap scav_2("Rick");

	scav.attack("Sam");
	scav.takeDamage(21);
	scav.beRepaired(22);
	scav.beRepaired(22);
	scav.guardGate();
	scav_2.attack("Bob");
	scav_2.takeDamage(101);
	scav_2.takeDamage(15);
	scav_2.attack("Bob");
	scav_2.beRepaired(22);
	
	ScavTrap scav_3(scav_2);
	scav_3.attack("Alice");
	scav_3.takeDamage(10);

	scav = scav_3;
	scav.attack("Alice");
}