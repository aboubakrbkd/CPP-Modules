#include "BitcoinExchange.hpp"

int main()
{
    // std::cout << "Hello" << std::endl;
    std::map<std::string, int>mp;
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;

    std::map<std::string, int>::iterator it = mp.begin();
    while (it != mp.end())
    {
        std::cout <<"Key: " << it->first <<" value: " << it->second << std::endl;
        it++;
    }
}