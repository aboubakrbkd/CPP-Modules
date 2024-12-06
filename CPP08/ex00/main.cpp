#include "easyfind.hpp"


int main()
{
	std::cout << "-----Testing Vector container-------" << std::endl;
    std::vector<int> v;

    v.push_back(15);
    v.push_back(20);
    v.push_back(355);
    v.push_back(432);
    v.push_back(5234);

    try {
        std::vector<int>::iterator it1 = easyfind(v, 15);
        std::cout << "Found at index: " << std::distance(v.begin(), it1) << std::endl;
        std::vector<int>::iterator it2 = easyfind(v, 4);
        std::cout << "Found at index: " << std::distance(v.begin(), it2) << std::endl;
    }
	catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << "------Testing List container--------" << std::endl;
	std::list<int> l;
    l.push_back(54);
    l.push_back(89456);
    l.push_back(321);
    l.push_back(421);
    l.push_back(5897);
	try {
		std::list<int>::iterator it1 = easyfind(l, 321);
		std::cout << "Found at index: " << std::distance(l.begin(), it1) << std::endl;
		std::list<int>::iterator it2 = easyfind(l, 3);
		std::cout << "Found at index: " << std::distance(l.begin(), it2) << std::endl;
	}
	catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << "--------Testing deque container-------" << std::endl;
	std::deque<int> d;
    d.push_back(54);
    d.push_back(89456);
    d.push_back(321);
    d.push_back(421);
    d.push_back(5897);
	try {
		std::deque<int>::iterator it1 = easyfind(d, 421);
		std::cout << "Found at index: " << std::distance(d.begin(), it1) << std::endl;
		std::deque<int>::iterator it2 = easyfind(d, 3);
		std::cout << "Found at index: " << std::distance(d.begin(), it2) << std::endl;
	}
	catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

}
