/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:35:43 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:35:43 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void cat_test()
{
	// Create cats
	Cat c;
	Cat b;
	c.makeSound();

	// Fill cat with ideas
	for (int i = 0; i < 100; i++)
		c.add_idea("Give me food");
	std::cout << c.get_idea(1) << std::endl;

	// copy assignment operator
	b = c;
	std::cout << b.get_idea(55)<< std::endl;

	// copy constracter
	Cat d(c);
	std::cout << b.get_idea(120)<< std::endl;

}

void dog_test()
{
	// Create dogs
	Dog *x = new Dog();
	Dog *y = new Dog();
	x->makeSound();

	// Fill dog with ideas
	for (int i = 0; i < 100; i++)
	{
		x->add_idea("Let's play");
		x->add_idea("I wanna eat");
	}
	std::cout << x->get_idea(5) << std::endl;

	// copy assignment operator
	*y = *x;
	std::cout << y->get_idea(50)<< std::endl;

	// copy constracter
	Dog *z = new Dog(*y);
	std::cout << z->get_idea(2)<< std::endl;

	delete x;
	delete y;
	delete z;
}

void brain_test()
{
	Brain brain_a;
	Brain brain_b;

	brain_a.add_idea("idea 1");
	brain_a.add_idea("idea 2");

	std::cout << brain_a.get_idea(0) << std::endl;

	// assignment
	brain_b = brain_a;
	std::cout << brain_b.get_idea(1) << std::endl;
	
	// copy constractor
	Brain brain_c(brain_b);
	std::cout << brain_c.get_idea(1) << std::endl;
}

int main()
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;

	// brain_test();
	// cat_test();
	// dog_test();
	
	// animal array
	// int animal_size = 10;
	// Animal *animals[animal_size];

	// for(int i = 0; i < animal_size; i++)
	// {
	// 	if (i % 2)
	// 		animals[i] = new Dog();
	// 	else
	// 		animals[i] = new Cat();
	// }

	// animals[0]->makeSound();

	// ((Dog *)animals[1])->add_idea("Let's play");
	// ((Dog *)animals[1])->add_idea("I wanna eat");

	// std::cout << ((Dog *)animals[1])->get_idea(0) << std::endl;
	
	// for (int i = 0; i < animal_size; i++)
	// 	delete animals[i];

	// Animal meta;
	return 0;
}