#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>

enum  {
	INT = 0,
	CHAR = 1,
	FLOAT = 2,
	DOUBLE = 3,
	PLUS_INFF = 4,
	MIN_INFF = 5,
	NANN = 6
};

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
	public:
		~ScalarConverter();
		static void	convert(const std::string& value);
		// i need to detect the type 
		// then i need to convert it from std::string to its actual type
		//then convert it to the 3 other type
};

#endif