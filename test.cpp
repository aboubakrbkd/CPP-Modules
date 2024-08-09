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

#include "Sed.hpp"

Sed::Sed()
{
    return ;
}

Sed::~Sed()
{
    std::cout << "Mission Complete" << std::endl;
}

std::string Sed::get_s1()
{
    return s1;
}

std::string Sed::get_s2()
{
    return s2;
}

void    Sed::set_s1(std::string name)
{
    this->s1 = name;
}

void    Sed::set_s2(std::string name)
{
    this->s2 = name;
}

void    Sed::replace(const std::string &filename)
{
    std::ifstream first_file(filename.c_str());
    if (!first_file)
    {
        std::cerr << "Error in opening the file!" << std::endl;
        return ;
    }
    std::ofstream output_file((filename + ".replace").c_str());
    if (!output_file)
    {
        std::cerr << "Error in creating the file!" << std::endl;
        return ;
    }
    std::ostringstream tmp;
    tmp << first_file.rdbuf();
    std::string str = tmp.str();

    size_t pos = 0;
    while ((pos = str.find(s1, pos)) != std::string::npos)
    {
        str.erase(pos, s1.length());
        str.insert(pos, s2);
        pos = pos + s2.length();
    }
    output_file << str;
}


#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Sed
{
    private:
        std::string s1;
        std::string s2;
    public:
        Sed();
        ~Sed();
        std::string get_s1();
        std::string get_s2();
        void    set_s1(std::string name);
        void    set_s2(std::string name);
        void    replace(const std::string &file); // Why we make const;
};


#endif

