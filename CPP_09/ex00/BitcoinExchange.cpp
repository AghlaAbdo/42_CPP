#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <map>

int	countChar(std::string &line, char c)
{
	int	count = 0;
	for (size_t i = 0; i < line.size(); i++)
		if (line[i] == c)
			count++;
	return (count);
}

int	parseLine(std::string &line)
{
	if (line.size() < 12 || countChar(line, '-') != 2
		|| countChar(line, ',') != 1 || countChar(line, '.') > 1)
		return (1);

	size_t pos = line.find('.');
	if (pos != std::string::npos && pos < 12)
		return (2);

	for (size_t i = 0; i < line.size(); i++) {
		if (!(line[i] >= '0' && line[i] <= '9') && line[i] != '-' 
				&& line[i] != ',' && line[i] != '.')
			return (3);
	}

	if (line[4] != '-' || line[7] != '-' || line[10] != ',')
		return (4);

	return (0);
}

void	insertPair(std::map<std::string, int> &data, std::string &line)
{
	std::string	key;
	double		val;

	key = line.substr(0, 10);

}

std::map<std::string, int>	readData(void)
{
	std::map<std::string, int>	data;
	std::ifstream	dataFile;
	std::string		line;

	dataFile.open("data.csv");
	if (dataFile.fail())
		throw std::runtime_error("Can't open data file");
	std::getline(dataFile, line);
	while (!dataFile.eof()) {
		std::getline(dataFile, line);
		int val = parseLine(line);
		if (val) {
			std::cout << "Val: " << val << std::endl;
			throw std::runtime_error("invaliddd");

		}
		insertPair(data, line);
	}

	dataFile.close();
	return (data);
}
