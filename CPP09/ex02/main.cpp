#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "The Program accept ./PmergeMe ..." << std::endl;
		return (1);
	}
	else
	{
		PmergeMe me;
		for (int i = 1; i < argc; i++)
			me.Ford_johnson(argv[i]);
	}

}

