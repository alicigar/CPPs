#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "\nHALF CATS, HALF DOGS" << std::endl;
	int	size = 100;
	Animal* animals[size];

	for (int i = 0; i < size/2; i++)
		animals[i] = new Dog();
	for (int i = size/2; i < size; i++)
		animals[i] = new Cat();
	for (int i = 0; i < size; i++)
		delete animals[i];
	
	std::cout << "\nDEEP COPY TEST" << std::endl;
	
	Dog dog1;
	dog1.getBrain()->setIdea(0, "Pipo");
	
	Dog dog2 = dog1;
	std::cout << "dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;
	
	std::cout << "\nAfter changing dog2:\n";
	dog2.getBrain()->setIdea(0, "I want chicken");
	std::cout << "dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;
	
	std::cout << "\nTESTING COPY" << std::endl;
	Dog* original = new Dog();
	original->getBrain()->setIdea(0, "Dog Island");
	Dog copy(*original);
	delete original;
    std::cout << copy.getBrain()->getIdea(0) << std::endl;

	std::cout << "\nOPERATORS" << std::endl;
	Cat a;
	a.getBrain()->setIdea(0, "Meow");
	Cat b;
	b = a;
	b.getBrain()->setIdea(0, "I hate seagulls");
	std::cout << a.getBrain()->getIdea(0) << std::endl;
	std::cout << b.getBrain()->getIdea(0) << std::endl;
	
	return 0;
}
