#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
		~ScalarConverter();

	public:
		static void convert(const std::string& literal);
};

#endif

//Recibes un string (argv[1]) que representa un literal de C++. 
//Averiguas de qué tipo es (char, int, float o double), lo conviertes a su tipo real 
//y luego lo conviertes con static_cast a los otros tres. 
//Imprimes los cuatro resultados, o “impossible” / “Non displayable” cuando no tenga sentido