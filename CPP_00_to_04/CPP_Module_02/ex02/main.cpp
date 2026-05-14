#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

/*

//Este ejercicio se trata de "enseñarle" a usar operadores a objetos de una clase 
//ya que por sí solos, no saben.

//Sobrecargar un operador: Darle una instrucción especial para TU clase
//ej: si tenemos Fixed a y Fixed b, dile que si a + b sume ambos Fixed

//ε: épsilon representa el incremento más pequeño posible
//ej: en nuestro caso, Fixed usa 8 bits para decimales. Entonces, el incremento más
//pequeño es 1/256 = 0.00390625

EXPECTED OUTPUT:

$> ./a.out
0				//Se crea un objeto "a" de tipo Fixed, inicializado a 0 por tanto ese el output
0.00390625		//
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>

*/

//Lo más complejo es entender esto: Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//1. Crea un objeto Fixed con valor 5.05 float
//2. Le aplico el operador de multiplicación (*)
//3. Lo multiplico por otro Fixed, con valor 2
//4. RESULTADO: 5.05 * 2 = 10.1
//5. Guardamos el resultado en Fixed const b (y como en const, entonces b no puede cambiar)

//++a: incrementa y devuelve el nuevo valor
//a++: incrementa pero devuelve el valor viejo
// << std::ostream: operador de salida 
