#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "The Program accepts ./PmergeMe ..." << std::endl;
        return (1);
    }
    else
    {
        PmergeMe me;
        std::string combinedArgs;
        for (int i = 1; i < argc; i++)
        {
            if (i > 1)
                combinedArgs += " ";
            combinedArgs += argv[i];
        }
        me.Ford_johnson(combinedArgs);
    }

    return 0;
}
