#pragma once
#include <vector>
#include "Vertex.h"

class Path
{
	std::vector <Vertex> vertex;
	int cost;

public:
	Path();
	~Path();

	int GetCost();
};

