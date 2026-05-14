#include "Fixed.hpp"

//LOS MENSAJES HAY QUE COMENTARLOS!!

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

//comparison operators
bool Fixed::operator>(const Fixed &src)const
{
	return (this->getRawBits() > src.getRawBits());
}

bool Fixed::operator<(const Fixed &src)const
{
	return (this->getRawBits() < src.getRawBits());
}

bool Fixed::operator>=(const Fixed &src)const
{
	return (this->getRawBits() >= src.getRawBits());
}

bool Fixed::operator<=(const Fixed &src)const
{
	return (this->getRawBits() <= src.getRawBits());
}

bool Fixed::operator==(const Fixed &src)const
{
	return (this->getRawBits() == src.getRawBits());
}

bool Fixed::operator!=(const Fixed &src)const
{
	return (this->getRawBits() != src.getRawBits());
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
Fixed &operator++();
Fixed operator++(int);
Fixed &operator--();
Fixed operator--(int);

//min min max max
static	Fixed &min(Fixed &a, Fixed &b);
static	const Fixed &min(const Fixed &a, const Fixed &b);
static	Fixed &max(Fixed &a, Fixed &b);
static	const Fixed &max(const Fixed &a, const Fixed &b);


/*

INCREMENTO (retornan Fixed o Fixed&):
 ++a     →  incrementa PRIMERO, retorna nuevo valor (referencia)
a++     →  incrementa DESPUÉS, retorna valor viejo (copia)
--a     →  decrementa PRIMERO
a--     →  decrementa DESPUÉS

MIN/MAX (estáticas):
Fixed::min(a, b)  →  retorna referencia al menor
Fixed::max(a, b)  →  retorna referencia al mayor

min con referencias mutables
min con referencias constantes
max con referencias mutables 
max con referncias constantes
*/
