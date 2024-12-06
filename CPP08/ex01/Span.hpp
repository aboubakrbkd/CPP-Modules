#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>


class Span {
	private:
		unsigned int max_int;
		std::vector<int> v;
		Span();
		Span& operator=(const Span& obj);
	public:
		Span(const Span& obj);
		Span(unsigned int n);
		~Span();
		void	addNumber(unsigned int n);
		int		shortestSpan();
		int		longestSpan();
		void	infinit_call(int size);
};

#endif