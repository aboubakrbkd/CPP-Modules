#include "Identify.hpp"
Base::~Base()
{
	std::cout << "Destructor called" << std::endl;
}

Base*	generate(void)
{
	srand(time(NULL));
	int random = rand() % 10 + 1;
	if (random > 0 && random <= 3)
		return (new A());
	else if (random >= 4 && random <= 6)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The Type is A!" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The type is B!" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The type is C!" << std::endl;
	else
		std::cout << "Unknown type!" << std::endl;
}

void	identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "The Type is A!" << std::endl;
		(void)a;
		return ;
	}
	catch (std::bad_cast&) {}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "The Type is B!" << std::endl;
		(void)b;
		return ;
	}
	catch (std::bad_cast& ) {}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "The Type is C!" << std::endl;
		(void)c;
		return ;
	}
	catch (std::bad_cast& ) {}
}