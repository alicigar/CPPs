#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &src)
{
	_brain = new Brain();
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		*this->_brain = *src._brain;
	}
	return *this;
}

Cat:: ~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "MIAU" << std::endl;
}

Brain *Cat::getBrain() const
{
	return this->_brain;
}
