#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &src)
{
	_brain = new Brain();
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		*this->_brain = *src._brain;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "GUAUUUU!!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return this->_brain;
}
