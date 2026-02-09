#include "Base.hpp"
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 10; i++)
	{
		Base* random = generate();
		identify(random);
	}
	return 0;
}