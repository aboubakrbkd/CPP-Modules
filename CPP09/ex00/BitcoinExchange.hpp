#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>
#include <cctype>

class Bitcoin {
    private:
        std::ifstream infile;
		std::ifstream data_file;
		std::map<std::string, double> mp;
	public:
		Bitcoin();
		~Bitcoin();
		Bitcoin(const Bitcoin& obj);
		Bitcoin& operator=(const Bitcoin& obj);
		void	parsing(std::string& file);
		void	loaddata();
		void	parseInputFile();
};

#endif