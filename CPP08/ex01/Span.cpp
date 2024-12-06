#include "Span.hpp"

Span::Span(unsigned int n) : max_int(n) {}

Span::~Span() {}

Span::Span(const Span& obj) 
{
	max_int = obj.max_int;
}

void	Span::addNumber(unsigned int n) 
{
	if (v.size() >= max_int)
		throw std::runtime_error("cannt add more");
	if (std::find(v.begin(), v.end(), n) != v.end())
		throw std::runtime_error("Duplicate error found");
	v.push_back(n);	
}

int	Span::shortestSpan()
{
	if (v.empty() || v.size() == 1)
		throw std::runtime_error("no span can be found");
	std::vector<int> v1 = v;
	std::sort(v1.begin(), v1.end());
	size_t min = INT_MAX;
	size_t diff;
	for (size_t i = 1; i < v1.size(); i++)
	{
		diff = v1[i] - v1[i - 1];
		if (diff < min)
			min = diff;
	}
	return (min);
}

int	Span::longestSpan()
{
	if (v.empty() || v.size() == 1)
		throw std::runtime_error("no span can be found");

	int end = *std::max_element(v.begin(), v.end());
	int begin = *std::min_element(v.begin(), v.end());

	return (end - begin);
}
