#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
	:_arr(new T[0]()), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
	:_arr(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &copy)
	:_arr(new T[copy.size()]()), _size(copy.size())
{
	for (size_t i = 0; i < _size; i++)
		_arr[i] = copy[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
T	&Array<T>::operator=(const Array &copy)
{
	delete[] _arr;
	_arr = new T[copy.size()]();
	_size = copy.size();
	for (size_t i = 0; i < _size; i++)
		_arr[i] = copy[i];
}

template <typename T>
T	&Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw std::out_of_range("index out of range");
	return (_arr[index]);
}

template <typename T>
const T	&Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw std::out_of_range("index out of range");
	return (_arr[index]);
}

template <typename T>
size_t	Array<T>::size(void) const
{
	return (_size);
}
