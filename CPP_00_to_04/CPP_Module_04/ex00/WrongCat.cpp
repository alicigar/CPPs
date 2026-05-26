#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrong Cat")
{
	std::cout << "Wrong cat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "Wrong cat copy constructor called" << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "Wrong cat assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongCat:: ~WrongCat()
{
	std::cout << "Wrong cat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "miaun't" << std::endl;
}