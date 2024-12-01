#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <limits>
#include <iomanip>
#include <exception>

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
		~ScalarConverter();
	public:
		static void	convert(const std::string& value);
};

// overflow
#endif