#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

int	countChar(std::string &line, char c)
{
	int	count = 0;
	for (size_t i = 0; i < line.size(); i++)
		if (line[i] == c)
			count++;
	return (count);
}

bool	parseLineData(std::string &line)
{
	if (line.size() < 12 || countChar(line, '-') != 2
		|| countChar(line, ',') != 1 || countChar(line, '.') > 1)
		return (false);

	size_t pos = line.find('.');
	if (pos != std::string::npos && pos < 12)
		return (false);

	for (size_t i = 0; i < line.size(); i++) {
		if (!(line[i] >= '0' && line[i] <= '9') && line[i] != '-' 
				&& line[i] != ',' && line[i] != '.')
			return (false);
	}

	if (line[4] != '-' || line[7] != '-' || line[10] != ',')
		return (false);

	return (true);
}

void	insertPair(std::map<std::string, double> &data, std::string &line)
{
	std::istringstream	strVal(line.substr(11));
	std::string	key = line.substr(0, 10);
	double		val;

	strVal >> val;
	if (strVal.fail())
		return ;
	data.insert(std::make_pair(key, val));

}

//	Read data from .csv file and store it in a map
std::map<std::string, double>	readData(void)
{
	std::map<std::string, double>	data;
	std::ifstream	dataFile;
	std::string		line;

	dataFile.open("data.csv");
	if (dataFile.fail())
		throw std::runtime_error("Can't open data file");
	while (!dataFile.eof()) {
		std::getline(dataFile, line);
		if (parseLineData(line))
			insertPair(data, line);
	}

	dataFile.close();
	return (data);
}


//	Input file part

bool	parseInputLine(std::string line)
{
	if (line.size() < 14 || countChar(line, ' ') != 2 || countChar(line, '-') > 3
		|| countChar(line, '|') != 1 || countChar(line, '.') > 1)
		return (false);

	if (countChar(line, '-') == 3) {
		if (line[13] == '-')
			return (true);
		return (false);
	}
	size_t pos = line.find('.');
	if (pos != std::string::npos && pos < 14)
		return (false);

	for (size_t i = 0; i < line.size(); i++) {
		if ((i == 4 || i == 7) && line[i] != '-')
			return (false);
		else if (i == 11 && line[i] != '|')
			return (false);
		else if ((i == 10 || i == 12) && line[i] != ' ')
			return (false);
		if (!(line[i] >= '0' && line[i] <= '9') && line[i] != '.'
			&& line[i] != ' ' && line[i] != '-' && line[i] != '|')
			return (false);
	}

	if (line[4] != '-' || line[7] != '-' || line[10] != ' '
		|| line[12] != ' ' || line[11] != '|')
		return (false);

	return (true);
}

std::map<std::string, double>::iterator	findNearestDate(std::map<std::string, double> &data, std::string key)
{
	std::map<std::string, double>::iterator	it;
	std::map<std::string, double>::iterator	lowest;


	lowest = data.end();
	for (it = data.begin(); it != data.end(); it++) {
		if (it->first < key && (lowest == data.end() || it->first > lowest->first))
			lowest = it;
	}
	if (lowest == data.end())
		return (data.begin());
	return (lowest);
}

//	find the date in the data base or the nearest one and calc
//	the value multiplied by the exchange rate
void	calcResult(std::map<std::string, double> &data, std::string line)
{
	std::istringstream	valStr(line.substr(13));
	std::string		key = line.substr(0, 10);
	double	val;

	(void)data;
	valStr >> val;
	if (valStr.fail()) {
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	if (val < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}
	else if (val > 1000) {
		std::cout << "Error: too large number." << std::endl;
		return ;
	}

	std::map<std::string, double>::iterator	it = data.find(key);
	if (it != data.end()) {
		std::cout << key << " => " << val << " = " << it->second * val << std::endl;
	}
	else {
		it = findNearestDate(data, key);
		std::cout << key << " => " << val << " = " << it->second * val << std::endl;
	}
}

//	Read data from input file
void	readInput(std::map<std::string, double> &data, std::string file)
{
	std::ifstream	inputFile;
	std::string		line;

	(void)data;
	inputFile.open(file.c_str());
	if (inputFile.fail())
		throw std::runtime_error("Can't open input file");
	std::getline(inputFile, line);
	while (!inputFile.eof()) {
		std::getline(inputFile, line);
		if (!line[0])
			continue;
		else if (parseInputLine(line))
			calcResult(data, line);
		else
			std::cout << "Error: bad input => " << line << std::endl;
	}
	inputFile.close();
}
