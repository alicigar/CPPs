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
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &src);
		~Fixed();
		Fixed &operator=(const Fixed &src);

		float toFloat(void) const;
		int 	toInt(void) const;

		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif
