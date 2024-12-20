#include "ScalarConverter.hpp"

int DetectType(const std::string& value)
{
	size_t count = 0;
	bool Digit = false;

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
	if (value.back() == 'f' && value.find('f') == value.length() - 1)
	{
		count = 0;
		Digit = false;
		for (size_t i = 0; i < value.length() - 1; i++)
		{
			if (value[i] == '.')
				count++;
			else if (std::isdigit(value[i]))
				Digit = true;
			else if (value[i] != '+' && value[i] != '-')
				break;
		}
		if (count == 1 && Digit)
			return (FLOAT);
	}
	for (size_t i = 0; i < value.length(); i++)
	{
	    if ((i == 0 && value[i] == '.') || (i == value.length() - 1 && value[i] == '.'))
	        return -1;
	    if (value[i] == '.')
	        count++;
	    else if (std::isdigit(value[i]))
	        Digit = true;
	    else if ((value[i] == '+' || value[i] == '-') && i == 0)
	        continue;
	    else
	        return -1;
	    if (count > 1)
	        return -1;
	}
	if (count == 1 && Digit)
    	return (DOUBLE);
	return (-1);
}

void	ScalarConverter::convert(const std::string& value)
{
	int type = DetectType(value);
	switch (type)
	{
		case 0 :
		{
			std::cout << "--Int---" << std::endl;
			int i;
			std::stringstream ss(value);
			ss >> i;
			if (!ss.fail())
			{
				std::cout << "char: ";
   				if (std::isprint(i))
					std::cout << '\'' << static_cast<char>(i) << '\'';
				else
					std::cout << "Non displayable";
				std::cout << "\n";
				std::cout << "int: " << i << "\n";
				std::cout << "float: " << std::fixed << std::setprecision(1)  << static_cast<float>(i) << "f\n";
				std::cout << "double: " << std::fixed << std::setprecision(1)  << static_cast<double>(i) << "\n";
				break;
			}
			else
			{
				std::cout << "char: ";
   				if (std::isprint(i))
					std::cout << '\'' << static_cast<char>(i) << '\'';
				else
					std::cout << "Non displayable";
				std::cout << "\n";
				std::cout << "int: " << "Non displayable" << "\n";
				std::cout << "float: " << std::fixed << std::setprecision(1)  << static_cast<float>(i) << "f\n";
				std::cout << "double: " << std::fixed << std::setprecision(1)  << static_cast<double>(i) << "\n";
				break;
			}
		}
		case 1:
		{
			std::cout << "---Char---" << std::endl;
			char c = value[0];
			std::cout << "char: ";
			if (std::isprint(static_cast<int>(c)))
				std::cout << '\'' << c << '\'';
			else
				std::cout << "Non displayable";
			std::cout << "\n";
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1)  << static_cast<float>(c) << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1)  << static_cast<double>(c) << std::endl;
			break;
		}
		case 2:
		{
			std::cout << "----Float---" << std::endl;
			std::string result = value;
			if (result.back() == 'f')
				result.pop_back();
			float f;
			std::stringstream ss(result);
			ss >> f;
			std::cout << "char: ";
			if (std::isprint(static_cast<int>(f)))
				std::cout<< '\'' << static_cast<char>(f) << '\'';
			else
				std::cout << "Non displayable";
			std::cout << "\n";
			std::cout << "int: " << static_cast<int>(f) << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1)  << static_cast<double>(f) << std::endl;
			break;
		}
		case 3:
		{
			std::cout << "--Double--" << std::endl;
			double d;
			std::stringstream ss(value);
			ss >> d;
			if (!ss.fail())
			{
				std::cout << "char: ";
				if (std::isprint(static_cast<int>(d)))
					std::cout << '\'' <<static_cast<char>(d) << '\'';
				else
					std::cout << "Non displayable";
				std::cout << "\n";
				std::cout << "int: " << static_cast<int>(d) << std::endl;
				std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" <<std::endl;
				std::cout << "double: " << d << std::endl;
				break;
			}
			else
			{
				std::cout<<"BINGO" << std::endl;
				break;
			}
		}
		case 4:
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << "inff" << std:: endl;
			std::cout << "double: " << "inf" << std::endl;
			break;
		}
		case 5:
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << "-inff" << std:: endl;
			std::cout << "double: " << "-inf" << std::endl;
			break;
		}
		case 6:
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << "nanf" << std:: endl;
			std::cout << "double: " << "nan" << std::endl;
			break;
		}
		default:
		{
			std::cout << "Unknown Type" << std::endl;
			break;
		}
	}
}
