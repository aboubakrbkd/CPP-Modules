#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>

template <typename T>
std::size_t function(T& arr, int occ)
{
    for (std::size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == occ)
            return (i);
    }
    throw std::runtime_error("Element not found"); 
}

#endif