#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <iostream>
#include <exception>

class Base {
	public:
		virtual ~Base();
};

class A : public Base {
};

class B : public Base {
	// ~B();
};

class C : public Base {
	// ~C();
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);


#endif