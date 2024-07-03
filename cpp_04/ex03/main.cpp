#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

void subjects_test()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void test_1()
{
	Ice ice;
	Cure cure;

	AMateria *manteria = ice.clone();
	std::cout << manteria->getType() << std::endl;

	Cure cure_2(cure);
	std::cout << cure_2.getType() << std::endl;
	
	delete manteria;
}

void test_2()
{
	Character a("bob");
	Character b("Alice");
	AMateria *m1 = new Ice();
	AMateria *m2 = new Cure();
	a.equip(m1);
	a.equip(m2);
	a.equip(m1);

	std::cout << "<-- 1 -->\n";
	a.use(1, b);
	a.use(0, b);
	a.use(3, b);

	std::cout << "<-- 2 -->\n";
	a.equip(m2->clone());
	a.equip(m1->clone());
	a.use(3, b);

	a.equip(m2->clone());
	a.equip(m2->clone());
	a.equip(m2->clone());
	a.equip(m2->clone());

	std::cout << "<-- 3 -->\n";
	a.unequip(1);
	a.use(1, b);

	std::cout << "<-- 4 -->\n";
	a.equip(m1->clone());
	a.use(1, b);

	Character c(a);

	std::cout << "<-- 5 -->\n";
	a.use(1, a);
	a.use(33, a);

	std::cout << "<-- 6 -->\n";
	b.use(3, a);

	b = c;

	std::cout << "<-- 7 -->\n";
	b.use(3, a);
	std::cout << b.getName() << "\n";

	c.unequip(0);
	c.unequip(1);
	c.unequip(188);

	a = c;

	std::cout << "<-- 8 -->\n";
	a.use(0, b);
	a.use(1, b);
	a.use(2, b);
}

void test_3()
{
	MateriaSource src;
	MateriaSource src_2;
	Character a("bob");
	Character b("Alice");

	AMateria *tmp = new Ice();
	src.learnMateria(tmp);
	src.learnMateria(tmp);
	src.learnMateria(tmp);
	tmp = new Cure();
	src.learnMateria(tmp);
	src.learnMateria(tmp);
	src.learnMateria(tmp);
	src.learnMateria(tmp);
	src.learnMateria(tmp);

	src_2 = src;
	
	a.equip(src_2.createMateria("cure"));
	a.use(0, b);

	MateriaSource src_3(src_2);
	b.equip(src_3.createMateria("cure"));
	b.use(0, a);
}

void test_4()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* alice = new Character("Alice");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	alice->equip(tmp);
	tmp = src->createMateria("cure");
	alice->equip(tmp);
	alice->equip(tmp);
	alice->equip(tmp->clone());
	alice->equip(tmp->clone());
	alice->equip(tmp->clone());

	ICharacter* bob = new Character("Bob");

	std::cout << "<-- 1 -->\n";
	alice->use(0, *bob);
	alice->use(1, *bob);
	alice->use(2, *bob);
	alice->use(-22, *bob);
	alice->use(55, *bob);

	std::cout << "<-- 2 -->\n";
	*(Character *)bob = *(Character *)alice;
	bob->use(1, *alice);

	std::cout << "<-- 3 -->\n";
	bob->unequip(1);
	bob->use(1, *alice);

	std::cout << "<-- 4 -->\n";
	tmp = src->createMateria("ice");
	bob->equip(tmp);
	bob->use(1, *alice);

	std::cout << "<-- 5 -->\n";
	alice->use(1, *bob);

	delete bob;
	delete alice;
	delete src;
}

int main()
{
	subjects_test();
	test_1();
	test_2();
	test_3();
	test_4();

}