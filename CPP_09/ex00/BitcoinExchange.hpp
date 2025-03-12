#pragma once

#include <map>
#include <string>

std::map<std::string, double>	readData(void);
void    readInput(std::map<std::string, double> &data, std::string file);