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
	
}

int main()
{
	ScalarConverter::convert("+inf");
}