#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <climits>

// std::vector container
void	fstParseArgs(std::vector<std::string> args);
void	fstConvertToInt(std::vector<int> &nums, std::vector<std::string> args);

//	std::deque container
void	secParseArgs(std::deque<std::string> args);
void	secConvertToInt(std::deque<int> &nums, std::deque<std::string> args);