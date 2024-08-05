/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:30:32 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:30:32 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
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

	ClapTrap clab_2(clap);
	clab_2.attack("Bob");
}