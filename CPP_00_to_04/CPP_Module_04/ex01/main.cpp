#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "Deep copy test" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "I am Pipo");

    Dog dog2(dog1);
    dog2.getBrain()->setIdea(0, "I love bones");

    std::cout << "dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	return 0;
}
