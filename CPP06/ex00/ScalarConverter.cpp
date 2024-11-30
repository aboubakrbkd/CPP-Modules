#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

int DetectType(const std::string& value)
{
	size_t count = 0;

	if (value == "-inf")
		return (MIN_INFF);
	if (value == "+inf")
		return (PLUS_INFF);
	if (value == "nan")
		return (NANN);
	if (value.length() == 1 && (std::isprint(value[0]) && !std::isdigit(value[0])))
		return(CHAR);
	for (size_t i = 0; i < value.length(); i++)
	{
		if (i == 0 && (value[i] == '+' || value[i] == '-'))
			continue;
		if (!std::isdigit(value[i]))
			break ;
		if (i == value.length() - 1)
            return (INT);
	}
	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == '.')
			count++;
		else if (!std::isdigit(value[i]) && (value[i] != '+' && value[i] != '-'))
			break ;
		if (i == value.length() - 1 && count == 1)
			return (DOUBLE);
	}
	if (value.back() == 'f')
	{
		count = 0;
		for (size_t i = 0; i < value.length() - 1; i++)
		{
			if (value[i] == '.')
				count++;
			else if (!std::isdigit(value[i]) && (value[i] != '+' && value[i] != '-'))
				break;
		}
		if (count == 1)
			return (FLOAT);
	}
	return (-1);
}

void	ScalarConverter::convert(const std::string& value)
{
	int type = DetectType(value);
	if (type == MIN_INFF || type == PLUS_INFF || type == NANN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << type << std:: endl;
		std::cout << "double: " << static_cast<double>(std::numeric_limits<float>::infinity()) << std::endl;
	}
	if (type == INT)
	{
		int i;
        std::stringstream(value) >> i;
        std::cout << "char: ";
   		if (std::isprint(i))
        	std::cout << static_cast<char>(i);
    	else
        	std::cout << "Non displayable";
    	std::cout << "\n";
        std::cout << "int: " << i << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1)  << static_cast<float>(i) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1)  << static_cast<double>(i) << "\n";
	}
	if (type == FLOAT)
	{
		std::cout << "value: " << value << std::endl;
	    std::string stripped_value = value;
        if (stripped_value.back() == 'f')
            stripped_value.pop_back();
		float f;
		std::stringstream(stripped_value) >> f;
		std::cout << "char: ";
		if (std::isprint(static_cast<int>(f)))
			std::cout<< static_cast<char>(f);
		else
			std::cout << "Non displayable";
		std::cout << "\n";
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1)  << static_cast<double>(f) << std::endl;
	}
	if (type == DOUBLE)
	{
		double d;
		std::stringstream(value) >> d;
		std::cout << "char: ";
		if (std::isprint(static_cast<int>(d)))
			std::cout << static_cast<char>(d);
		else
			std::cout << "Non displayable";
		std::cout << "\n";
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" <<std::endl;
		std::cout << "double: " << d << std::endl;
	}
	if (type == CHAR)
	{
		char c = value[0];
		std::cout << "char: ";
		if (std::isprint(static_cast<int>(c)))
			std::cout << c;
		else
			std::cout << "Non displayable";
		std::cout << "\n";
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1)  << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1)  << static_cast<double>(c) << std::endl;
	}
}

int main()
{
	ScalarConverter::convert("nan");
}