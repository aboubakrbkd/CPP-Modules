#include "RPN.hpp"

int main(int argc, char**argv)
{
    if (argc != 2)
	{
		std::cerr << "The programe accept ./RPN arg1" << std::endl;
		return (1);
	}
	RPN::Reverse_polish_notaion(argv[1]);
}