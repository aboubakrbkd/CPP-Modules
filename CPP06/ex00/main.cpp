#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void) argv;
	if (argc != 2)
	{
		std::cerr << "The output need to be ./convert arg1" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}