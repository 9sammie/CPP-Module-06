#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert() {}

ScalarConvert::ScalarConvert(const ScalarConvert& other) {}

ScalarConvert& ScalarConvert::operator = (const ScalarConvert& other)
{
	return (*this);
}

ScalarConvert::~ScalarConvert() {}

void ScalarConvert::convert(const std::string& literal)
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
