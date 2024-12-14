#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};
PmergeMe::~PmergeMe() {};
PmergeMe::PmergeMe(const PmergeMe& obj) {(void)obj;};
PmergeMe& PmergeMe::operator=(const PmergeMe& obj){(void)obj; return *this;};


std::vector<int> GenerateJacobsthalSequence(std::size_t n)
{
    std::vector<int> jacob_seq;
    jacob_seq.push_back(0);
    jacob_seq.push_back(1);

    for (std::size_t i = 2; i < n; i++)
    {
        std::size_t next = jacob_seq[i - 1] + 2 * jacob_seq[i - 2];
        jacob_seq.push_back(next);
    }
    return (jacob_seq);
}

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

void MergeChains(std::deque<int>& main_chain, std::deque<int>& pend_chain)
{
    for (std::size_t i = 0; i < pend_chain.size(); ++i)
    {
        int element = pend_chain[i];
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

void DivideandSortPairs(std::deque<int>& deq)
{
    clock_t start = clock();
    std::size_t len = deq.size();
    bool hasUnpaired = (len % 2 == 1);
    int lastElement = 0;
    if (hasUnpaired)
    {
        lastElement = deq.back();
        deq.pop_back();
    }
	std::vector<std::pair<int, int> > pairs;
    for (std::size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        int a = deq[i];
        int b = deq[i + 1];
        if (a < b)
            std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
    }
	InsertionSort(pairs);
	deq.clear();
	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		deq.push_back(pairs[i].first);
		deq.push_back(pairs[i].second);
	}
	std::deque<int> main_chain;
	std::deque<int> pend_chain;
	for (std::size_t i = 0; i < deq.size(); i++)
	{
		if (i % 2 == 0)
		   main_chain.push_back(deq[i]);
		else
		    pend_chain.push_back(deq[i]);
	}
	if (!pend_chain.empty())
    {
        main_chain.insert(main_chain.begin(), pend_chain.front());
        pend_chain.erase(pend_chain.begin());
    }
	MergeChains(main_chain, pend_chain);
    if (hasUnpaired)
    { 
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
        main_chain.insert(main_chain.begin() + low, lastElement);
    }
    deq.clear();
    deq = main_chain;
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "Time to process a range of " << main_chain.size() << " elements with std::deque ";
    std::cout << duration << " ms" << std::endl;
}

void MergeChains(std::vector<int>& main_chain, std::vector<int>& pend_chain)
{
    for (std::size_t i = 0; i < pend_chain.size(); ++i)
    {
        int element = pend_chain[i];
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
    clock_t start = clock();
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
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
        main_chain.insert(main_chain.begin() + low, lastElement);
    }
    vec.clear();
    vec = main_chain;
    std::cout << "after:  ";
    for (std::size_t i = 0; i < main_chain.size(); ++i)
        std::cout << main_chain[i] << " ";
    std::cout << std::endl;
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "Time to process a range of " << main_chain.size() << " elements with std::vector ";
    std::cout << duration << " ms" << std::endl;
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
            de.push_back(num);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
	}
    DivideandSortPairs(vec);
    DivideandSortPairs(de);
}
