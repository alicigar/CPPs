#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("")
{
	std::cout << "Wrong Animal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "Wrong Animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "Wrong Animal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "Wrong Animal assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "A generic wrong animal sound" << std::endl;
}