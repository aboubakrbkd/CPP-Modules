#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {}

Bitcoin::~Bitcoin() {}

Bitcoin::Bitcoin(const Bitcoin& obj) {(void)obj;};

Bitcoin& Bitcoin::operator=(const Bitcoin& obj) {(void)obj; return *this;};

void	Bitcoin::parsing(const std::string& file)
{
	if (file.size() < 4 || file.substr(file.size() - 4) != ".txt")
        throw std::invalid_argument("Input file must have a .txt extension");
	infile.open(file);
	if (!infile.is_open())
		throw std::runtime_error("Cannot open The infile");
	data_file.open("data.csv");
	if (!data_file.is_open())
		throw std::runtime_error("Cannot open The Data.csv");
}

void	Bitcoin::loaddata()
{
	std::string line;
	if (std::getline(data_file, line))
	{
		if (line != "date,exchange_rate")
			std::cerr << "Invalid header in input file date,exchange_rate" << std::endl;
		return ;
	}
	while (std::getline(data_file, line))
	{
		std::stringstream ss(line);
		std::string date, value_date;
		double value;
		if (!std::getline(ss, date, ',') || !std::getline(ss, value_date))
		{
            std::cerr << "Invalid line in data file: " << line << std::endl;
            continue;
        }
		std::stringstream value_s(value_date);
		if (!(value_s >> value) || !value_s.eof())
		{
            std::cerr << "Invalid value in data file: " << value << std::endl;
            continue;
        }
		mp[date] = value;
	}
	data_file.close();
}

bool isValidDate(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); ++i)
	{
        if ((i != 4 && i != 7) && !std::isdigit(date[i]))
            return false;
    }
    int year;
	int month;
	int day;
    std::stringstream ss(date);
    char dash1;
	char dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;
    if (dash1 != '-' || dash2 != '-')
        return false;
    if (month < 1 || month > 12)
        return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2)
	{
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth[1] = 29;
    }
    if (day < 1 || day > daysInMonth[month - 1])
        return false;
    return true;
}

void	Bitcoin::parseInputFile()
{
	std::string line;
	std::string date;
	if (std::getline(infile, line))
	{
		if (line != "date | value")
		{
			std::cerr << "Invalid header in input file date | value" << std::endl;
				return ;
		}
	}
	while (std::getline(infile, line))
	{
		std::stringstream ss(line);
		if (!std::getline(ss, date, '|'))
		{
			std::cerr << "Invalid line format in input file: " << line << std::endl;
            continue;
		}
		size_t first = date.find_first_not_of(" \t");
        size_t last = date.find_last_not_of(" \t");
        date = date.substr(first, (last - first + 1));
		if (!isValidDate(date))
		{
			std::cerr << "Invalid date: " << std::endl;
			continue;
		}
		else{
			std::cout << "ok" << std::endl;
			continue;
		}
	}
}