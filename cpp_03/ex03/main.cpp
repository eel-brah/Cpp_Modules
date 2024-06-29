#include "DiamondTrap.hpp"

int main()
{
	// std::cout << "<<----- CLAPTRAP ----->>\n" << std::endl;
	// ClapTrap clap("Karl");

	// clap.attack("Sam");
	// clap.takeDamage(4);
	// clap.takeDamage(3);
	// clap.beRepaired(5);
	// clap.takeDamage(10);
	// clap.attack("Alice");
	// clap.beRepaired(10);
	// clap.attack("Alice");
	// clap.beRepaired(5);
	// for (int frag_3 = 0; frag_3 < 12; frag_3++)
	// 	clap.attack("Sam");
	// clap.beRepaired(3);

	// std::cout << "\n\n<<----- SCAVTRAP ----->>\n" << std::endl;
	// ScavTrap scav;
	// ScavTrap scav_2("Rick");

	// scav.attack("Sam");
	// scav.takeDamage(21);
	// scav.beRepaired(22);
	// scav.beRepaired(22);
	// scav.guardGate();
	// scav_2.attack("Bob");
	// scav_2.takeDamage(101);
	// scav_2.takeDamage(15);
	// scav_2.attack("Bob");
	// scav_2.beRepaired(22);
	
	// ScavTrap scav_3(scav_2);
	// scav_3.attack("Alice");
	// scav_3.takeDamage(10);

	// scav = scav_3;
	// scav.attack("Alice");

	// std::cout << "\n\n<<----- SCAVTRAP ----->>\n" << std::endl;
	// FragTrap frag;
	// FragTrap frag_2("Rick");

	// frag.attack("Sam");
	// frag.takeDamage(21);
	// frag.beRepaired(22);
	// frag.beRepaired(22);
	// frag.highFivesGuys();
	// frag_2.attack("Bob");
	// frag_2.takeDamage(101);
	// frag_2.takeDamage(15);
	// frag_2.attack("Bob");
	// frag_2.beRepaired(22);
	
	// FragTrap frag_3(frag_2);
	// frag_3.attack("Alice");
	// frag_3.takeDamage(10);

	// frag = frag_3;
	// frag.attack("Alice");

	std::cout << "\n\n<<----- DIAMONDTRAP ----->>\n" << std::endl;
	DiamondTrap Diam;
	DiamondTrap Diam_2("Rick");

	Diam.attack("Sam");
	Diam.takeDamage(21);
	Diam.beRepaired(22);
	Diam.beRepaired(22);
	Diam.highFivesGuys();
	Diam.whoAmI();
	Diam_2.attack("Bob");
	Diam_2.takeDamage(101);
	Diam_2.takeDamage(15);
	Diam_2.attack("Bob");
	Diam_2.beRepaired(22);
	
	DiamondTrap Diam_3(Diam_2);
	Diam_3.attack("Alice");
	Diam_3.takeDamage(10);

	Diam = Diam_3;
	Diam.attack("Alice");
}