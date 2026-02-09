#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

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

class ScalarConvert
{
	private:
	ScalarConvert();
	ScalarConvert(const ScalarConvert&);
	ScalarConvert& operator = (const ScalarConvert&);
	~ScalarConvert();

	public:
	static void convert(const std::string& literal);
};

int literalType(const std::string& literal);
void cast(const std::string& literal, int type);
bool toCharFromInt(int i, char& c);
bool toInt(const std::string& s, int& out);
bool toDouble(const std::string& s, double& out);
bool toFloatFromDouble(double d, float& f);
void print_char(const bool& char_ok, const char& c);
void print_int(const bool& int_ok, const int& i);
void print_double(const bool& double_ok, const double& d);
void print_float(const bool& float_ok, const float& f);

#endif