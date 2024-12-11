#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};
PmergeMe::~PmergeMe() {};
PmergeMe::PmergeMe(const PmergeMe& obj) {(void)obj;};
PmergeMe& PmergeMe::operator=(const PmergeMe& obj){(void)obj; return *this;};


bool isValidNumber(const std::string& result)
{
	if (result.empty())
		return false;
	for (std::size_t i = 0; i < result.size(); i++)
	{
		if (!std::isdigit(result[i]))
            return false;
	}
	return true;
}

// void	DivideandSortPairs(std::vector<int> &vec, std::size_t start = 0)
// {
//     if (start + 1 >= vec.size()) 
//         return; 
// 	for (std::size_t i = 0; i + 1 < vec.size(); i += 2)
// 	{
// 		int a = vec[i];
// 		int b = vec[i + 1];
// 		if (a > b)
// 			std::swap(a, b);
// 		DivideandSortPairs(vec, 1);
// 	}
// }

void DivideandSortPairs(std::vector<int>& vec, int pair_level)
{
    typedef std::vector<int>::iterator Iterator;

    // Calculate the number of "pair units" for the given pair_level
    int pair_units_nbr = vec.size() / pair_level;
    if (pair_units_nbr < 2) 
        return;  // Stop if there are fewer than two pairs.

    // Handle the odd pair case.
    bool is_odd = pair_units_nbr % 2 == 1;

    // Calculate the bounds for the current level of iteration
    Iterator start = vec.begin();
    Iterator last = std::next(vec.begin(), pair_level * pair_units_nbr);
    Iterator end = std::next(last, -(is_odd * pair_level)); // Exclude any incomplete pair at the end.

    // Swap pairs of elements at the current pair_level.
    int jump = 2 * pair_level;
    for (Iterator it = start; it != end; std::advance(it, jump))
    {
        Iterator this_pair = std::next(it, pair_level - 1); // Last element of this pair
        Iterator next_pair = std::next(it, pair_level * 2 - 1); // Last element of next pair
        if (*this_pair > *next_pair)
        {
            std::swap(*this_pair, *next_pair);  // Swap the two pairs
        }
    }

    // Recursively process the next level of pairs, doubling the pair size.
    DivideandSortPairs(vec, pair_level * 2);
}

void	PmergeMe::Ford_johnson(const std::string& result)
{
	std::stringstream ss(result);
	std::vector<int> small;
    std::vector<int> big;
    std::string tmp;
    int num;
	while (ss >> tmp)
	{
        if (isValidNumber(tmp))
        {
            std::stringstream num_stream(tmp);
            num_stream >> num;
            vec.push_back(num);
        }
        else
        {
            std::cerr << "Invalid number: " << std::endl;
            exit(1);
        }

	}
	std::cout << "Before:";
	for (std::size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
    DivideandSortPairs(vec, 1);
	std::cout << "after:";
	for (std::size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
} 
