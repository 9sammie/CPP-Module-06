#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>

enum type
{
	INT,
	DOUBLE,
	FLOAT,
	CHAR,
	OTHER,
};

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator = (const ScalarConverter&);
	~ScalarConverter();

	public:
	static void convert(const std::string& literal);
};



int literalType(const std::string& literal);
void cast(const std::string& literal, int type);

bool stringToInt(const std::string& s, int& i);
bool stringToDouble(const std::string& s, double& d);
bool stringToFloat(const std::string& s, float& f);

bool intToChar(int i, char& c);
bool intToDouble(int i, double& d);
bool intToFloat(int i, float& f);

bool doubleToChar(double d, char& c);
bool doubleToInt(double d, int& i);
bool doubleToFloat(double d, float& f);

bool floatToChar(float f, char& c);
bool floatToInt(float f, int& i);
bool floatToDouble(float f, double& d);

void print_char(const bool& char_ok, const char& c);
void print_int(const bool& int_ok, const int& i);
void print_double(const bool& double_ok, const double& d);
void print_float(const bool& float_ok, const float& f);

#endif