#include "Bureaucrat.hpp"

int main()
{
    try {
        std::cout << "Creating Bureaucrat with valid grade..." << std::endl;
        Bureaucrat aboubakr("aboubakr", 42);
        std::cout << aboubakr << std::endl;

        std::cout << "Incrementing aboubakr's grade..." << std::endl;
        aboubakr.increment();
        std::cout << aboubakr << std::endl;

        std::cout << "Decrementing aboubakr's grade..." << std::endl;
        aboubakr.decrement();
        std::cout << aboubakr << std::endl;

        std::cout << "Creating Bureaucrat with too high grade..." << std::endl;
        Bureaucrat high("High", 0);
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
        std::cout << "Creating Bureaucrat with too low grade..." << std::endl;
        Bureaucrat low("Low", 151);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
        std::cout << "Testing increment beyond limits..." << std::endl;
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        top.increment();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Testing decrement beyond limits..." << std::endl;
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
        bottom.decrement();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "All tests completed." << std::endl;
}