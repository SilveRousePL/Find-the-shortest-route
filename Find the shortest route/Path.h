#pragma once
#include <sstream>
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

	friend std::ostream & operator <<(std::ostream & ostr, Path obj);
};