#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat("Aboubakr", 160);
    }
    catch(std::exception& e) {
        std::cout << "Eroor: " << e.what() << std::endl;
    }

    try {
        Bureaucrat("Aboubakr", 0);
    }
    catch(std::exception &e)
    {
        std::cout << "Eroor: " << e.what() << std::endl;
    }

    try {
        Bureaucrat a("Aboubakr", 150);
        a.increment();
    }
    catch(std::exception& e)
    {
        std::cout << "Eroor: " << e.what() << std::endl;
    }
    try {
        Bureaucrat a("Aboubakr", 1);
        a.decrement();
    }
    catch(std::exception& e)
    {
        std::cout << "Eroor: " << e.what() << std::endl;
    }
}