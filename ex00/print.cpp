#include "ScalarConvert.hpp"
#include <iomanip>

void print_char(const bool& char_ok, const char& c)
{
	if (!char_ok)
		std::cout << "char: impossible\n";
	else if (!std::isprint(c))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << c << "'\n";
}

void print_int(const bool& int_ok, const int& i)
{
	if (!int_ok)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << i << "\n";
}

void print_double(const bool& double_ok, const double& d)
{
	if (!double_ok)
		std::cout << "double: impossible\n";
	else if (std::isnan(d))
		std::cout << "double: nan\n";
	else if (std::isinf(d))
		std::cout << "double: " << (d < 0 ? "-inf\n" : "+inf\n");
	else
	{
        std::cout << "double: ";
        std::cout << std::fixed << std::setprecision(1);
        std::cout << d << "\n";
	}
}

void print_float(const bool& float_ok, const float& f)
{
	if (!float_ok)
		std::cout << "float: impossible\n";
	else if (std::isnan(f))
		std::cout << "float: nanf\n";
	else if (std::isinf(f))
		std::cout << "float: " << (f < 0 ? "-inff\n" : "+inff\n");
	else
	{
        std::cout << "float: " << f;
        std::cout << "f\n";
	}
}