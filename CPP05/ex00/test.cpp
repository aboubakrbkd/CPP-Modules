#include <iostream>

int main()
{
    std::string name = "four";

    try
    {
        std::cout << name.at(4) << std::endl;
    }
    catch(out_of_range &e)
    {
        std::cout <<"Execption detected!" << std::endl;
    }
}