#include "Sed.hpp"

int main(int argc, char **argv)
{
    Sed str;
    std::string str1;
    std::string str2;
    if (argc != 4)
        std::cout << "Pleas enter a file and the two string to manipulate " << std::endl;
    else
    {
        str1 = argv[2];
        str2 = argv[3];
        str.set_s1(str1);
        str.set_s2(str2);
        str.replace(argv[1]);
    }
}