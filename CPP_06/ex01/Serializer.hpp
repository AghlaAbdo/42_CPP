#pragma once

#include <iostream>
#include <cstdint>
#include "data.h"

class	Serializer {
private:
	Serializer(void);
	Serializer(const Serializer &copy);
	~Serializer();
	Serializer	&operator=(const Serializer &copy);

public:
	static uintptr_t	serialize(Data *ptr);
	static Data*		deserialize(uintptr_t raw);
};