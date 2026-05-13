#include "Fixed.hpp"

Fixed::Fixed() : _fpvalue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fpvalue = src._fpvalue;
	return *this;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_fpvalue = n * (1 << _fbits);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_fpvalue = roundf(f * (1 << _fbits));
}

float Fixed::toFloat(void) const
{
	return _fpvalue / (float)(1 << _fbits);
}

int Fixed::toInt(void) const
{
	return _fpvalue / (1 << _fbits);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fpvalue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fpvalue = raw;
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return o;
}
