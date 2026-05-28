#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrong Cat")
{
	std::cout << "Wrong Cat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "Wrong Cat copy constructor called" << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "Wrong Cat assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongCat:: ~WrongCat()
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "miaun't" << std::endl;
}