#pragma once

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void)
	: std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
	: std::stack<T>()
{
	this->c = copy.c;
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &copy)
{
	this->c = copy.c;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}
