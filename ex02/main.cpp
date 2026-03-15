#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << GREYBG << "    --- Tests Random ---    " << STD << std::endl << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Test " << i + 1 << ":" << std::endl;

		Base* instance = generate();

		std::cout << "  Identify by pointer:   ";
		identify(instance);

		std::cout << "  Identify by reference: ";
		identify(*instance);

		delete instance; 
	}

	std::cout << "\n" << GREYBG << "     --- NULL case ---      " << STD << std::endl << std::endl;

	std::cout << "NULL pointer identification:" << std::endl;
	identify(NULL);

	return 0;
}
