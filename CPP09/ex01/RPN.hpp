#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <stdexcept>
#include <cstdlib>


class RPN {
    public:
        RPN();
        ~RPN();
        RPN(const RPN& obj);
        RPN& operator=(const RPN& obj);
		static void Reverse_polish_notaion(const std::string& result);
};

#endif