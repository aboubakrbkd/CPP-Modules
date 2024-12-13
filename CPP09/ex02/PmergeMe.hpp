#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>
#include <sstream>

class PmergeMe {
	private:
		std::vector<int> vec;
		std::deque<int> de;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
		~PmergeMe();
		void Ford_johnson(const std::string& result);	
};

#endif