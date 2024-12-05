#include "easyfind.hpp"

int main()
{
    std::vector<int> v;

    v.push_back(15);
    v.push_back(20);
    v.push_back(355);
    v.push_back(432);
    v.push_back(5234);

    try {
        std::size_t i = function(v, 15);
        std::cout << "Element found at index: " << i << std::endl;
        std::size_t f = function(v, 4);
        std::cout << "Element found at index: " << f << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}