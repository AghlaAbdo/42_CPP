#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <climits>
#include <sys/time.h>
#include <cstdio>

// std::vector container
void	fstParseArgs(std::vector<std::string> args);
void	fstConvertToInt(std::vector<std::pair<int, int> > &nums, std::vector<std::string> args);
void	fstSortNums(std::vector<std::pair<int, int> > &nums);
void    fstSortPairs(std::vector<std::pair<int, int> > &nums);
void    fstSplitPairs(std::vector<std::pair<int, int> > &nums, std::vector<int> &main, std::vector<int> &pend);
void	fstGenerateJacobNums(std::vector<int> &jacobNums, size_t pendSize);
void	fstInsertToMain(std::vector<int> &jacobNums, std::vector<int> &main, std::vector<int> &pend);

//	std::deque container
void	secParseArgs(std::deque<std::string> args);
void	secConvertToInt(std::deque<int> &nums, std::deque<std::string> args);