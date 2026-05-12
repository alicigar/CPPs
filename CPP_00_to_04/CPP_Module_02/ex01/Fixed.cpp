#include "Fixed.hpp"

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