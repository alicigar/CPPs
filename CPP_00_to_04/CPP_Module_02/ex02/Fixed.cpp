#include "Fixed.hpp"

//LOS MENSAJES HAY QUE COMENTARLOS!!

Fixed::Fixed() : _fpvalue(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fpvalue = src._fpvalue;
	return *this;
}

Fixed::Fixed(const int n)
{
	//std::cout << "Int constructor called" << std::endl;
	_fpvalue = n * (1 << _fbits);
}

Fixed::Fixed(const float f)
{
	//std::cout << "Float constructor called" << std::endl;
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
	//std::cout << "getRawBits member function called" << std::endl;
	return _fpvalue;
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	_fpvalue = raw;
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return o;
}

//comparison operators
bool Fixed::operator>(const Fixed &src)const
{
	if (this->getRawBits() > src.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator<(const Fixed &src)const
{
	if (this->getRawBits() < src.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator>=(const Fixed &src)const
{
	if (this->getRawBits() >= src.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator<=(const Fixed &src)const
{
	if (this->getRawBits() <= src.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator==(const Fixed &src)const
{
	if (this->getRawBits() == src.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator!=(const Fixed &src)const
{
	if (this->getRawBits() != src.getRawBits())
		return true;
	else
		return false;
}

//arithmetics operators
Fixed Fixed::operator+(const Fixed &src)
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed &src)
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed &src)
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed &src)
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

//increment and decrement operators
Fixed &Fixed::operator++()
{
	this->_fpvalue += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fpvalue += 1;
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->_fpvalue -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fpvalue -= 1;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
