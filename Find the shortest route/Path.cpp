#include "Path.h"

using namespace std;

Path::Path(vector<int> & id_vertex, int cost) : vertex(id_vertex), cost(cost)
{}

Path::~Path()
{}

vector<int> Path::getPath() const
{
	return vertex;
}

int Path::getCost() const
{
	return cost;
}
