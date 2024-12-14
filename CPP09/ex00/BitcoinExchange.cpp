#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {}

Bitcoin::~Bitcoin() {if (infile.is_open()) infile.close();};

Bitcoin::Bitcoin(const Bitcoin& obj) {(void)obj;};

Bitcoin& Bitcoin::operator=(const Bitcoin& obj) {(void)obj; return *this;};

void	Bitcoin::parsing(std::string& file)
{
	if (file.size() < 4 || file.substr(file.size() - 4) != ".txt")
        throw std::invalid_argument("Input file must have a .txt extension");
	infile.open(file.c_str());
	if (!infile.is_open())
		throw std::runtime_error("Cannot open The infile");
	data_file.open("data.csv");
	if (!data_file.is_open())
		throw std::runtime_error("Cannot open The Data.csv");
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

bool isValidValue(std::string& value)
{
	int count = 0;
	if (value.empty() || value[0] == '-')
    {
        std::cerr << "Error: not a positive number" << std::endl;
        return false;
    }
	for (size_t i = 0; i < value.size(); i++)
	{
		if ((i == 0 && value[i] == '.') || (i == value.size() - 1 && value[i] == '.'))
			return false;
		if (value[i] == '.')
			count++;
		else if (!std::isdigit(value[i]))
			return false;
	}
	if (count > 1)
		return false;
	std::stringstream ss(value);
	int num;
	ss >> num;
	if (ss.fail() || num > 1000 || num < 0)
    {
        std::cerr << "Error: too large a number." << std::endl;
		return false;
    }
	return true;
}

void	Bitcoin::loaddata()
{
	std::string line;
	if (std::getline(data_file, line))
	{
		if (line != "date,exchange_rate")
		{
			std::cerr << "Invalid header in input file date,exchange_rate" << std::endl;
				return ;
		}
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

void	Bitcoin::parseInputFile()
{
	std::string line;
	std::string date;
	std::string value_s;
	if	(std::getline(infile, line))
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
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (!isValidDate(date))
		{
			std::cerr << "Invalid date: " << std::endl;
			continue;
		}
		if (!std::getline(ss, value_s))
		{
			std::cerr << "Missing value" << std::endl;
			continue;
		}
		size_t first_value = value_s.find_first_not_of(" \t");
        size_t last_value = value_s.find_last_not_of(" \t");
        value_s = value_s.substr(first_value, (last_value - first_value + 1));
        if (!isValidValue(value_s))
            continue;
        double value;
        std::stringstream sss(value_s);
        sss >> value;
        std::map<std::string, double>::iterator it = mp.lower_bound(date);
        if (it != mp.end() && it->first == date)
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		else
		{
			if (it != mp.begin())
			{
				it--;
				if (it->first < date)
					std::cout << date << " => " << value << " = " << it->second * value << std::endl;
				else
					std::cerr << "No date found in the data.csv for: " << date << std::endl;
			}
			else
				std::cerr << "No date found in the data.csv for: " << date << std::endl;
		}
    }
}