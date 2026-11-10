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

//falta por implementar

static bool isPseudo(const std::string& s);   // nan, +inf, -inf, nanf, +inff, -inff
static bool isChar(const std::string& s);     // char
static bool isInt(const std::string& s);      // float
static bool isFloat(const std::string& s);    // signo?, dígitos, un '.', dígitos, 'f' final
static bool isDouble(const std::string& s);   // igual que float, sin 'f'

// ---------- IMPRESIÓN (todas reciben el valor como double) ----------
static void printChar(double v);
static void printInt(double v);
static void printFloat(double v);
static void printDouble(double v);

// ---------- convert ----------
void ScalarConverter::convert(const std::string& literal)
{
    double value;

    // 1. Detectar tipo en este orden: pseudo, char, int, float, double
    // 2. Sacar el valor como double:
    //      char   -> static_cast<double>(literal[0])
    //      int    -> strtod(literal.c_str(), NULL)
    //      float  -> quitar la 'f' final y strtod
    //      double -> strtod
    //      pseudo -> quitar la 'f' si la hay y strtod (strtod entiende nan/inf)
    //      ninguno -> imprimir error y return
    // 3. printChar(value); printInt(value); printFloat(value); printDouble(value);
}