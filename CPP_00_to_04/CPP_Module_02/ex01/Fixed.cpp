#include "Fixed.hpp"

//Constructor por defecto
Fixed::Fixed() : _fpvalue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Constructor de copia
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
}

//Operador de asignación
Fixed &Fixed &operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fpvalue = src.getRawBits();
	return *this;
}

//Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//Constructor con int
Fixed(int const n)
{

}

//Constructor con float


//FUNCIONES
float toFloat(void) const
{
	std::cout << "Float constructor called" << std::endl;
	//_fpvalue = roundf(f * 256.0f)
}

int 	toInt(void) const
{
	//return _fpvalue / 256.0f;
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

//convierte el Fixed a float e imprime ese float en el stream y devuelve ostream para poder encadenar

//float y double ambos son decimales pero float más pequeño que double
//en cpp los decimales son por defecto double por ello se debe especificar con f si son float

//fixed-point es una forma de guardar número decimales usando solo entero
//ej: el número 3.14 como tipo float, ocupa 4 bytes, tiene decimales
//pero en entero es 803 ocupa 2 bytes pero representa 3.14
//funciona decidiendo cuantos bits usas para decimales, en nuestro caso 8 porque no lo pide el subject
//eso significa: valor real = valor guardado / 256
//osea guardo 803 que 803/256=3.134...
//es como tener dinero: en vez de guardar 3,14$ guardas 314 centavos y luego divides por 100 cuando quieres saber cuantos dolares osn



/*
EXPECTED OUT:


$> ./a.out
Función para: Default constructor called
Función para: Int constructor called
Función para: Float constructor called
Función para: Copy constructor called
Función para: Copy assignment operator called
Función para: Destructor called


*/
