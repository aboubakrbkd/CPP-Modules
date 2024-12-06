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
	std::cout << "---Full Element Test---"<< std::endl;
	Span sp4(3);
	sp4.addNumber(1);
	sp4.addNumber(654);
	sp4.addNumber(64);
	try {
		sp4.addNumber(15);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---Large Element Test---" << std::endl;
    Span sp5(1000);
	std::vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);
	test.push_back(6);
	test.push_back(7);
	test.push_back(8);
	test.push_back(9);
	test.push_back(10);
    try {
		sp5.infinit_call<std::vector<int> >(test.begin(), test.end());
        std::cout << "Shortest Span: " << sp5.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp5.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}
