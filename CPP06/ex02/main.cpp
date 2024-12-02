#include "Identify.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cerr << "The program accept only one parameter!!" <<  std::endl;
		return (1);
	}
	Base* p = generate();
	std::cout << "Identifying p.." << std::endl;
	identify(p);
	Base* a = generate();
	Base& f = *a;
	std::cout << "Identifying f..." << std::endl;
	identify(f);
	delete a;
	delete p;

}