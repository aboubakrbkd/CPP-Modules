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
		template <typename T>
		void	infinit_call(typename T::iterator begin, typename T::iterator end){
			size_t size = std::distance(begin, end);
			if (v.size() + size > max_int)
				throw std::runtime_error("Span is full");
			v.insert(v.end(), begin, end);
		};

};

#endif