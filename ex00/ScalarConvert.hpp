/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:57:10 by maballet          #+#    #+#             */
/*   Updated: 2026/01/21 19:11:09 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>

enum type
{
	INT = 1,
	DOUBLE = 2,
	FLOAT = 3,
	CHAR = 4,
	OTHER = 5,
};

class ScalarConvert
{
	public:
	ScalarConvert();
	ScalarConvert(const std::string literal);
	ScalarConvert& operator = (const ScalarConvert&);
	~ScalarConvert();
	
	private:
	static void convert(const std::string& literal);
};

int literalType(const std::string& literal);
void convertAndPrint(const std::string& literal, int type);

#endif