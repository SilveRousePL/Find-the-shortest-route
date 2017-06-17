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

ostream & operator <<(ostream & ostr, Path obj)
{
	if (obj.getPath().size() == 0)
	{
		ostr << "Path doesn't exist";
	}
	else
	{
		ostr << "Shortest path = ( ";
		for (auto i = 0; i < obj.getPath().size(); i++)
		{
			ostr << obj.getPath()[i];
			if (i+1 != obj.getPath().size()) ostr << "-";
		}
		ostr << " ) ### Cost = " << obj.getCost();
	}
	return ostr;
}