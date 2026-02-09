#include "ScalarConvert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "2 arguments expected as follow: ./ScalarConvert <argument>" << std::endl;
		return 1;
	}
	ScalarConvert::convert(argv[1]);
	return 0;
}
