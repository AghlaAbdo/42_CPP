#pragma once

#include <algorithm>
#include <sstream>
#include <string>

template <typename T>
typename T::iterator easyfind(T &cont, int value)
{
	typename T::iterator	it = find(cont.begin(), cont.end(), value);
	if (it != cont.end())
		return (it);

	std::string err = "Value: ";
    std::ostringstream oss;
    oss << value;
    err += oss.str();
	err += " Not found";

	throw std::runtime_error(err);
}
