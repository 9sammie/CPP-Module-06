/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:46:34 by maballet          #+#    #+#             */
/*   Updated: 2026/01/21 20:50:12 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"
#include <climits>

int literalType(const std::string& literal)
{
	if (!literal.compare("nan") || !literal.compare("-inf") || !literal.compare("+inf"))
		return (DOUBLE);
	if (!literal.compare("nanf") || !literal.compare("-inff") || !literal.compare("+inff"))
		return (FLOAT);
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return (CHAR);

	int i = 0;
	int dotCount = 0;
	int digitCount = 0;
	int fCount = 0;

	while (literal[i])
	{
		if (literal[i] == '+' || literal[i] == '-')
		{
			if (i != 0)
				return (OTHER);
		}
		else if (std::isdigit(literal[i]))
			digitCount++;
		else if (literal[i] == '.')
		{
			if (dotCount > 0 || i == 0)
				return (OTHER);
			dotCount++;
		}
		else if (literal[i] == 'f')
		{
			if (fCount > 0 || i == 0 || dotCount == 0 || literal[i+1])
				return (OTHER);
			fCount++;
		}
		i++;
	}
	if (digitCount == 0)
		return (OTHER);
	if (dotCount == 0 && fCount == 0)
		return (INT);
	if (dotCount == 1 && fCount == 0)
		return (DOUBLE);
	if (dotCount == 1 && fCount == 1)
		return (FLOAT);
	return (OTHER);
}

static void print_all(const char& c, const int& i, const float& f, const double& d)
{
	std::cout << "char: ";
	if (d < 0 || d > 127 || std::isnan(d))
		std::cout << "impossible\n";
	else if (!std::isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << c << "'\n";


	std::cout << "int: ";
	if (d < INT_MIN || d > INT_MAX || std::isnan(d))
		std::cout << "impossible\n";
	else
		std::cout << i << "\n";

	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf\n";
	else if (std::isinf(f))
		std::cout << (f < 0 ? "-inff\n" : "+inff\n");
	else
	{
		std::cout << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f\n";
	}

	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan\n";
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inf\n" : "+inf\n");
	else
	{
		std::cout << d;
		if (d == static_cast<int>(d))
			std::cout << ".0";
		std::cout << "\n";
	}
}

void convertAndPrint(const std::string& literal, int type)
{
	char	c;
	int		i;
	float	f;
	double	d;

	try
	{
		if (type == CHAR)
		{
			c = literal[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
		}
		else if (type == INT)
		{
			i = std::atoi(literal.c_str());
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
		}
		else if (type == FLOAT)
		{
			f = std::atof(literal.c_str());
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
		}
		else if (type == DOUBLE)
		{
			d = std::atof(literal.c_str());
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
		}
		else
			throw std::exception();
	}
	catch (...)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}
	print_all(c, i, f, d);
}
