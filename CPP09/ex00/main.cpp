#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "The programme accept ./btc filename.txt" << std::endl;
		return (1);
	}
	try {
		Bitcoin btc;
		btc.parsing(argv[1]);
		btc.loaddata();
		btc.parseInputFile();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}