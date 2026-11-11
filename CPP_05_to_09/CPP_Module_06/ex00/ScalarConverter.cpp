#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return(*this);
}

ScalarConverter::~ScalarConverter() {}

static void printAll(double v)
{
    //char
    std::cout << "char: ";
    if (v < 0 || v > 127)
        std::cout << "impossible";
    else if (v < 32 || v == 127)
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(v) << "'";
    std::cout << std::endl;

    //int
    std::cout << "int: ";
    if (v < -2147483648.0 || v > 2147483647.0)
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(v);
    std::cout << std::endl;

    //float: always one decimal, then 'f'
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(v) << "f" << std::endl;

    //double: always one decimal
    std::cout << "double: " << v << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    //1. Special cases; compare as text
    if (literal == "nan" || literal == "nanf" || literal == "+inf" ||
    literal == "+inff" || literal == "-inf" || literal == "-inff")
    {
        std::string f = "nanf";
        std::string d = "nan";
        if (literal[0] == '+')
        {
            f = "+inff";
            d = "+inf";
        }
        else if (literal[0] == '-')
        {
            f = "-inff";
            d = "-inf";
        }
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << f << std::endl;
        std::cout << "double: " << d << std::endl;
        return ;
    }
    
    //2. Char = one letter, not a digit
    if (literal.length() == 1 && (literal[0] < '0' || literal[0] > '9'))
    {
        printAll(static_cast<double>(literal[0]));
        return ;
    }
    //3. Read the text letter by letter
    size_t i = 0;
    int digits = 0;
    int dots = 0;
    bool hasF = false;
    bool valid = true;

    if (literal.length() > 0 && (literal[0] == '+' || literal[0] == '-'))
        i = 1;
    while (i < literal.length())
    {
        if (literal[i] >= '0' && literal[i] <= '9')
            digits++;
        else if (literal[i] == '.')
            dots++;
        else if (literal[i] == 'f' && i == literal.length() - 1)
            hasF = true;
        else
            valid = false;
        i++;
    }
    //4. Check if the literal is valid
    if (!valid || digits == 0 || dots > 1 || (hasF && dots == 0))
    {
        std::cout << "Error: invalid literal." << std::endl;
        return ;
    }

    //5. Get the value with atof and print it
    printAll(atof(literal.c_str()));
}
