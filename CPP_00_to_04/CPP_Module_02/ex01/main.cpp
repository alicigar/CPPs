#include "Fixed.hpp"

int main( void ) 
{
	Fixed a; //se llama al constructor por defecto Fixed() e inicializa a._fpvalue = 0;
	Fixed const b(10); //se llama al constructor que recibe int y 10 se convierte a FP 10 * 256 y b._fpvalue es 2560
	Fixed const c(42.42f); //se llama al contructor que recibe float y 42.42f se convierte a FP roundf(42.42f * 256) c._fpvalue = 10852
	Fixed const d(b); //se llama al constructor de copia y copia b en d asi que d._fpvalue es 2560
	
	a = Fixed(1234.4321f); //se crea un Fixed temporal.  Esto es lo más complejo. 
	//Llama al constructor que recibe float
	//roundf(1234.4321 * 256) = 315887
	//Este objeto temporal tiene _fpvalue = 315887
	//Output: Float constructor called
	//a = ... asigna ese temporal a a
	//Llama al operador de asignación (operator=)
	//a._fpvalue = 315887
	//Output: Copy assignment operator called

	std::cout << "a is " << a << std::endl; //imprime los valores actuales de a,b,c y d
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl; //los convierte a int *256 (?)
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}

/*
EXPECTED OUT:


$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>


 */