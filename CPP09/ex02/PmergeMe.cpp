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

void InsertionSort(std::vector<std::pair<int, int> >& pairs)
{
    for (std::size_t i = 1; i < pairs.size(); ++i)
    {
       std::pair<int, int> key = pairs[i];
       int j = i - 1;
        while (j >= 0 && pairs[j].first > key.first) 
        {
            pairs[j + 1] = pairs[j];
            --j;
        }
        pairs[j + 1] = key;
    }
}

std::vector<int> GenerateJacob(int n)
{
    std::vector<int> jacob;
    int i = 0;
    while (true)
	{
        int j = (1 << i) - (i % 2 == 0 ? 1 : -1) / 3;
        if (j >= n) 
		    break;
        jacob.push_back(j);
        i++;
    }
    return (jacob);
}


void MergeChains(std::vector<int>& main_chain, std::vector<int>& pend_chain)
{
    std::vector<int> jacob = GenerateJacob(pend_chain.size());
    
    for (std::size_t k = 0; k < jacob.size(); ++k)
	{
        std::size_t index = jacob[k];
        if (index >= pend_chain.size())
		      break;
        int element = pend_chain[index];
        int low = 0;
		int high = main_chain.size();
        while (low < high)
		{
            int mid = low + (high - low) / 2;
            if (main_chain[mid] < element)
                low = mid + 1;
			else 
                high = mid;
        }
        main_chain.insert(main_chain.begin() + low, element);
    }
}


void DivideandSortPairs(std::vector<int>& vec)
{
    std::size_t len = vec.size();
    bool hasUnpaired = (len % 2 == 1);
    int lastElement = 0;
    if (hasUnpaired)
    {
        lastElement = vec.back();
        vec.pop_back();
    }
	std::vector<std::pair<int, int> > pairs;
    for (std::size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        int a = vec[i];
        int b = vec[i + 1];
        if (a < b)
            std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
    }
	InsertionSort(pairs);
	vec.clear();
	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		vec.push_back(pairs[i].first);
		vec.push_back(pairs[i].second);
	}
	std::vector<int> main_chain;
	std::vector<int> pend_chain;
	for (std::size_t i = 0; i < vec.size(); i++)
	{
		if (i % 2 == 0)
		   main_chain.push_back(vec[i]);
		else
		    pend_chain.push_back(vec[i]);
	}
	if (!pend_chain.empty())
    {
        main_chain.insert(main_chain.begin(), pend_chain.front());
        pend_chain.erase(pend_chain.begin());
    }
	MergeChains(main_chain, pend_chain);
	if (hasUnpaired)
    {
        vec.push_back(lastElement);
        int low = 0;
        int high = main_chain.size();
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (main_chain[mid] < lastElement)
                low = mid + 1;
            else
                high = mid;
        }
        main_chain.insert(main_chain.begin() + low, vec.back());
    }
	std::cout << "Final Main Chain: ";
    for (std::size_t i = 0; i < main_chain.size(); ++i)
      std::cout << main_chain[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::Ford_johnson(const std::string& result)
{
	std::stringstream ss(result);
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
    DivideandSortPairs(vec);
} 