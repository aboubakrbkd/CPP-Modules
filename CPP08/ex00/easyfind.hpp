#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <list>

template <typename T>
typename T::iterator  easyfind(T& arr, int occ)
{
	typename T::iterator it = std::find(arr.begin(), arr.end(), occ);
	if (it == arr.end())
		throw(std::runtime_error("Element not found"));
	return (it); 
}

#endif