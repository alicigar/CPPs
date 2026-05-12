#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int _fpvalue;
		static const int _fbits = 8;
	public:
		Fixed();
		Fixed(const Fixed &src);
		~Fixed();
		Fixed &operator=(const Fixed &src);
		Fixed(int const n);
		Fixed(float const f);
		float toFloat(void) const;
		int 	toInt(void) const;
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif

//ostream es el tipo de std::cout, significa Output STREAM
// << es operador de inserción
//std::cout << int/float/str sabe pero de FixedPoint number:NO y debemos enseñarle

//la función std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
//devuelve una referencia a un ostream, el mismo std::cout que recibí
//para poder hacer std::cout << a << " y " << b osea para encadenar cosas
//operator<< es el nombre de la función