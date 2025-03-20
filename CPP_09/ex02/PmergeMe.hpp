#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <climits>
#include <sys/time.h>
#include <cstdio>

// std::vector container
void	ParseArgs(std::vector<std::string> args);
void	ConvertToInt(std::vector<std::pair<int, int> > &nums, std::vector<std::string> args);
void	SortNums(std::vector<std::pair<int, int> > &nums);
void    SortPairs(std::vector<std::pair<int, int> > &nums);
void    SplitPairs(std::vector<std::pair<int, int> > &nums, std::vector<int> &main, std::vector<int> &pend);
void	GenerateJacobNums(std::vector<int> &jacobNums, size_t pendSize);
void	InsertToMain(std::vector<int> &jacobNums, std::vector<int> &main, std::vector<int> &pend);

//	std::deque container
void	ParseArgs(std::deque<std::string> args);
void	ConvertToInt(std::deque<std::pair<int, int> > &nums, std::deque<std::string> args);
void	SortNums(std::deque<std::pair<int, int> > &nums);
void    SortPairs(std::deque<std::pair<int, int> > &nums);
void    SplitPairs(std::deque<std::pair<int, int> > &nums, std::deque<int> &main, std::deque<int> &pend);
void	GenerateJacobNums(std::deque<int> &jacobNums, size_t pendSize);
void	InsertToMain(std::deque<int> &jacobNums, std::deque<int> &main, std::deque<int> &pend);
