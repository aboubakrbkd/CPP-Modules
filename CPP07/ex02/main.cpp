#include "Array.hpp"

int main(int, char**)
{
    Array<int> numbers(20);
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		numbers[i] = i;
		std::cout << numbers[i] << std::endl;
	}
	try {
		numbers[21] = 5;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}