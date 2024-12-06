#include "Span.hpp"

int main()
{
	std::cout << "---Subject Test---" << std::endl;
	Span sp0 = Span(5);
	sp0.addNumber(6);
	sp0.addNumber(3);
	sp0.addNumber(17);
	sp0.addNumber(9);
	sp0.addNumber(11);
	std::cout << sp0.shortestSpan() << std::endl;
	std::cout << sp0.longestSpan() << std::endl;
	std::cout << "---EmptySpan Test---" << std::endl;
	Span sp1 = Span(0);
	try {
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "---SingleElementSpan Test---" << std::endl;
	Span sp2 = Span(1);
	sp2.addNumber(6);
	try {
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "---Identical Element Test---" << std::endl;
	Span sp3 = Span(3);
	try {
		sp3.addNumber(6);
		sp3.addNumber(6);
		sp3.addNumber(5);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "---Large Element Test---" << std::endl;
    Span sp4(1000);
	sp4.infinit_call(1000);
    try {
        std::cout << "Shortest Span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp4.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}
