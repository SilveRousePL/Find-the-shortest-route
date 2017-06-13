#pragma once
#include <cstdint>
#include "Exceptions.h"

class Array2D
{
	int8_t ** array;
	size_t size;

public:
	Array2D(size_t size);
	Array2D(const Array2D& obj);
	~Array2D();
	Array2D & operator=(const Array2D& obj);

	int8_t & at(size_t x, size_t y) const;
	int8_t ** getArray() const;
};

