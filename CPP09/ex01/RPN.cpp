#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& obj) {(void)obj;};
RPN& RPN::operator=(const RPN& obj) {(void)obj; return*this;};

bool is_number(std::string& token)
{
	if (token.empty())
        return false;
    std::stringstream number_s(token);
    double number;
    number_s >> number;
    return !number_s.fail() && number_s.eof();
}

bool is_operator(const std::string& token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::Reverse_polish_notaion(const std::string& result)
{
	std::stringstream ss(result);
	std::stack<double> s;
	
	std::string token;
	while (ss >> token)
    {
        if (is_number(token))
		{
			std::stringstream number_s(token);
			double number;
			number_s >> number;
			if (number >= 10)
			{
				std::cerr << "Error" << std::endl;
				exit(1);
			}
			if (number < 0)
			{
				std::cerr << "Error" << std::endl;
				exit(1);
			}
			s.push(number);
		}
		else if (is_operator(token))
		{
			if (s.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				exit(1);
			}
			double b = s.top(); s.pop();
            double a = s.top(); s.pop();
			if (token == "+")
				s.push(a + b);
			else if (token == "-")
				s.push(a - b);
			else if (token == "*")
				s.push(a * b);
			else if (token == "/")
				s.push(a / b);
		}
		else 
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
    }
	if (s.size() == 1)
	{
		double result = s.top();
		std::cout << result << std::endl;
	}
	else
	{
		std::cerr << "Eroor" << std::endl;
		exit(1);
	}
}
