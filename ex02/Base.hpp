#ifndef BASE_HPP
#define BASE_HPP

#define STD			"\033[0m"
#define GREEN		"\033[38;5;34m\033[48;5;193m"
#define PINK		"\033[38;5;199m\033[48;5;225m"
#define BLUE		"\033[38;5;44m\033[48;5;159m"

#include <cstdlib>
#include <iostream>

class Base
{
	public:

	virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif