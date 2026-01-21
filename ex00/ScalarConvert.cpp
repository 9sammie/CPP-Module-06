/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:56:41 by maballet          #+#    #+#             */
/*   Updated: 2026/01/21 20:55:16 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert() {}

ScalarConvert::ScalarConvert(const std::string literal) {}

ScalarConvert& ScalarConvert::operator = (const ScalarConvert&) {

	return(*this);
}

ScalarConvert::~ScalarConvert() {}

void ScalarConvert::convert(const std::string& literal)
{
	int type;
	if (literal.empty())
		return;
	type = literalType(literal);
	convertAndPrint(literal, type);
}
