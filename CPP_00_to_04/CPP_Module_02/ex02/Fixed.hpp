#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

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

		int	getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int 	toInt(void) const;

		//comparison operators
		bool operator>(const Fixed &src)const;
		bool operator<(const Fixed &src)const;
		bool operator>=(const Fixed &src)const;
		bool operator<=(const Fixed &src)const;
		bool operator==(const Fixed &src)const;
		bool operator!=(const Fixed &src)const;

		//arithmetics operators
		Fixed operator+(const Fixed &src);
		Fixed operator-(const Fixed &src);
		Fixed operator*(const Fixed &src);
		Fixed operator/(const Fixed &src);
	
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

};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif
