#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {}

ScalarConverter& ScalarConverter::operator = (const ScalarConverter& other)
{
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
	int type;
	if (literal.empty())
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "double: impossible\n";
		std::cout << "float: impossible\n";
		return;
	}
	type = literalType(literal);
	cast(literal, type);
}
