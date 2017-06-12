#pragma once
#include <vector>
#include "Vertex.h"

class Path
{
	std::vector <Vertex> vertex;
	size_t cost;

public:
	Path();
	~Path();

	size_t getCost() const;
};

