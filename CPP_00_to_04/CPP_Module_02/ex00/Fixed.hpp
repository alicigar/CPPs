#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <string>

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
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};
#endif
