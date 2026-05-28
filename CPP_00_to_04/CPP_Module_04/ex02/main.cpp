#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
//#include "Brain.hpp"

int	main()
{
    //AAnimal* test = new AAnimal();

    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;
	
    return 0;
}
