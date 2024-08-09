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
