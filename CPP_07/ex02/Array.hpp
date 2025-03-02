#pragma once

template <typename T>
class	Array {
private:
	T 		*_arr;
	size_t	_size;

public:
	Array(void);
	Array(unsigned int n);
	Array(const Array &copy);
	~Array();
	T	&operator=(const Array &copy);
	T	&operator[](size_t index);
	const T	&operator[](size_t index) const;
	size_t	size(void) const;
};

#include "Array.tpp"
