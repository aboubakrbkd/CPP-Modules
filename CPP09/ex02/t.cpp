#include <iostream>
#include <algorithm>
#include <vector>

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

int main()
{
    std::vector<int> ve = GenerateJacobsthalSequence(6);
    for (std::size_t i = 0; i < ve.size(); ++i)
        std::cout << ve[i] << " ";
    std::cout << std::endl;
}