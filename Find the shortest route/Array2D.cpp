#include "Array2D.h"

using namespace std;

Array2D::Array2D(size_t size)
{
	if (size <= 0) throw CriticalException("Wrong size in Array2D object");
	this->size = size;
	array = new int8_t *[size];
	for (auto i = 0; i < size; i++)
		array[i] = new int8_t[size];
}

Array2D::Array2D(const Array2D & obj)
{
	size = obj.size;
	array = new int8_t *[obj.size];
	for (auto i = 0; i < size; i++)
		array[i] = new int8_t[size];

	for (auto i = 0; i < obj.size; i++)
		for (auto j = 0; j < obj.size; i++)
			array[i][j] = obj.array[i][j];
}

Array2D::~Array2D()
{
	for (auto i = 0; i < size; i++) delete array[i];
	delete array;
}

Array2D & Array2D::operator =(const Array2D & obj)
{
	if (this != &obj)
	{
		for (auto i = 0; i < size; i++) delete array[i];
		delete array;

		array = new int8_t *[obj.size];
		for (auto i = 0; i < size; i++)
			array[i] = new int8_t[size];

		for (auto i = 0; i < obj.size; i++)
			for (auto j = 0; j < obj.size; i++)
				array[i][j] = obj.array[i][j];
	}
	return *this;
}

int8_t & Array2D::at(size_t x, size_t y) const
{
	if (x<size && y<size)
		return array[x][y];
	throw CriticalException("Read out of range in Array2D object");
}

int8_t ** Array2D::getArray() const
{
	return array;
}