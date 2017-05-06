#pragma once
#include <vector>
#include "Vertex.h"

using namespace std;

class Path
{
	vector<Vertex> vertex;
	int cost;

public:
	Path();
	~Path();

	int GetCost();
};

