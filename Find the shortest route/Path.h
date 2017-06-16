#pragma once
#include <vector>

class Path
{
	std::vector <int> vertex;
	int cost;

public:
	Path(std::vector <int> & id_vertex, int cost);
	~Path();
	std::vector<int> getPath() const;
	int getCost() const;
};