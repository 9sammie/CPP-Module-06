#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void)
{
	int r = std::rand() % 3;

	if (r == 0)
		return new A;
	if (r == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << PINK << " A " << STD << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << GREEN << " B " << STD << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << BLUE << " C " << STD << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << PINK << " A " << STD << std::endl;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << " B " << STD << std::endl;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << " C " << STD << std::endl;
	}
	catch (...) {}
}
