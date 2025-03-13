#include <iostream>
#include <stack>
#include "RPN.hpp"

void	calcExpression(std::string const &arg)
{
	std::stack<int>		operands;
	int	fst;
	int	sec;
	int	res;
	
	for (size_t i = 0; i < arg.size(); i++) {
		if ((arg[i] >= '0' && arg[i] <= '9')) {
			operands.push(arg[i] - 48);
		}
		else if (arg[i] != ' ') {
			if (operands.empty())
				throw std::runtime_error("Error: Need more operands");
			fst = operands.top();
			operands.pop();
			if (operands.empty())
				throw std::runtime_error("Error: Need more operands");
			sec = operands.top();
			operands.pop();
			if (arg[i] == '+')
				res = sec + fst;
			else if (arg[i] == '-')
				res = sec - fst;
			else if (arg[i] == '*')
				res = sec * fst;
			else if (arg[i] == '/')
				res = sec / fst;
			operands.push(res);
		}
	}
	if (operands.size() > 1)
		throw std::runtime_error("Error: Too many operands");
	std::cout << operands.top() << std::endl;
}