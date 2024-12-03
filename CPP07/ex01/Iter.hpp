#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename E,typename  M>

void	iter(T *a, E size, M &fun)
{
	for (int i = 0; i < size; i++)
		fun(a[i]);
}

#endif