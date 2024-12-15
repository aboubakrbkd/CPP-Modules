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
        if (next >= n)
            break;
        jacob_seq.push_back(next);
    }
    std::vector<int> result;
    result.push_back(jacob_seq[0]);
    for (std::size_t i = 2; i < jacob_seq.size(); i++)
    {
        int current = jacob_seq[i];
        int previous = jacob_seq[i - 1];
        result.push_back(current);
        for (int j = current - 1; j > previous; j--)
        {
            result.push_back(j);
        }
    }
    return result;
}

std::deque<int> GenerateJacobsthalSequence_de(std::size_t n)
{
    std::deque<int> jacob_seq;
    jacob_seq.push_back(0);
    jacob_seq.push_back(1);

    for (std::size_t i = 2; i < n; i++)
    {
        std::size_t next = jacob_seq[i - 1] + 2 * jacob_seq[i - 2];
        if (next >= n)
            break;
        jacob_seq.push_back(next);
    }
    std::deque<int> result;
    result.push_back(jacob_seq[0]);
    for (std::size_t i = 2; i < jacob_seq.size(); i++)
    {
        int current = jacob_seq[i];
        int previous = jacob_seq[i - 1];
        result.push_back(current);
        for (int j = current - 1; j > previous; j--)
        {
            result.push_back(j);
        }
    }
    return result;
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


void InsertionSort(std::deque<std::pair<int, int> >& pairs)
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

void InsertUsingBinarySearch(std::deque<int>& main_chain, int element)
{
    int low = 0, high = main_chain.size();
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

void MergeChains(std::deque<int>& main_chain, std::deque<int>& pend_chain)
{
    std::deque<int> jacob = GenerateJacobsthalSequence_de(pend_chain.size());
    std::deque<bool> inserted(pend_chain.size(), false);
    for (std::size_t k = 0; k < jacob.size(); ++k)
    {
        std::size_t index = jacob[k];
        if (index >= pend_chain.size())
            break;
        if (!inserted[index])
        {
            InsertUsingBinarySearch(main_chain, pend_chain[index]);
            inserted[index] = true;
        }
    }
    for (std::size_t i = 0; i < pend_chain.size(); ++i)
    {
        if (!inserted[i])
            InsertUsingBinarySearch(main_chain, pend_chain[i]);
    }
}

void DivideandSortPairs(std::deque<int>& vec)
{
    clock_t start = clock();
    std::size_t len = vec.size();
    bool hasUnpaired = (len % 2 == 1);
    int lastElement = 0;
    if (hasUnpaired)
    {
        lastElement = vec.back();
        vec.pop_back();
    }
	std::deque<std::pair<int, int> > pairs;
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
	std::deque<int> main_chain;
	std::deque<int> pend_chain;
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
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "Time to process a range of " << main_chain.size() << " elements with std::deque ";
    std::cout << duration << " ms" << std::endl;
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

void InsertUsingBinarySearch(std::vector<int>& main_chain, int element)
{
    int low = 0, high = main_chain.size();
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

void MergeChains(std::vector<int>& main_chain, std::vector<int>& pend_chain)
{
    std::vector<int> jacob = GenerateJacobsthalSequence(pend_chain.size());
    std::vector<bool> inserted(pend_chain.size(), false);
    for (std::size_t k = 0; k < jacob.size(); ++k)
    {
        std::size_t index = jacob[k];
        if (index >= pend_chain.size())
            break;
        if (!inserted[index])
        {
            InsertUsingBinarySearch(main_chain, pend_chain[index]);
            inserted[index] = true;
        }
    }
    for (std::size_t i = 0; i < pend_chain.size(); ++i)
    {
        if (!inserted[i])
            InsertUsingBinarySearch(main_chain, pend_chain[i]);
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
