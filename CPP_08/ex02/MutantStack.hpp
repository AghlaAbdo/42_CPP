#pragma once

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class	MutantStack : public std::stack<T> {
public:
	MutantStack(void);
	MutantStack(const MutantStack &copy);
	~MutantStack();
	MutantStack	&operator=(const MutantStack &copy);

	typedef typename std::deque<T>::iterator iterator;
	iterator	begin();
	iterator	end();
};

#include "MutantStack.tpp"
