#include "Search.h"
#include <iostream>

using namespace std;

Search::Search(Matrix & adjacency_matrix, int id_begin, int id_end) : size(adjacency_matrix.size()), id_begin(id_begin), id_end(id_end)
{
	if (size < 2) throw WarningException("Graph is too little");

	this->adjacency_matrix = new int *[size];
	for (auto i = 0; i < size; i++)
		this->adjacency_matrix[i] = new int[size];

	for (auto i = 0; i < size; i++)
		for (auto j = 0; j < size; j++)
			this->adjacency_matrix[i][j] = adjacency_matrix[i][j];

	tmp_path_.reserve(size);

	generateVertexMap_();

	useVertex_(id_begin);
	look_(0, 0, id_begin);
	releaseVertex_(id_begin);
}

Search::~Search()
{
	if (result != nullptr) delete result;
	for (auto i = 0; i < size; i++) delete vertex_map[i];
	delete vertex_map;
	for (auto i = 0; i < size; i++) delete adjacency_matrix[i];
	delete adjacency_matrix;
}

Path Search::getShortestPath() const
{
	if (result == nullptr) throw WarningException("Path doesn't exist");
	return *result;
}

void Search::look_(int deep, int sum, int current)
{
	for (auto i = 0; i < size; i++)
	{
		if (current == id_end)
		{
			if (result == nullptr)
			{
				result = new Path(tmp_path_, sum);
			}
			if (sum < result->getCost())
			{
				delete result;
				result = new Path(tmp_path_, sum);
			}
		}

		auto next = vertex_map[current][i];
		if (next < 0) return;
		if (isUsedVertex_(next)) continue;

		//Inicjalizacja wej�cia do nast�pnego w�z�a
		useVertex_(next);
		look_(deep + 1, sum + adjacency_matrix[current][next], next);
		releaseVertex_(next);
	}
}

void Search::generateVertexMap_()
{
	vertex_map = new int *[size];
	for (auto i = 0; i < size; i++)
		vertex_map[i] = new int[size];
	auto * vertex_cost = new int[size];

	for (auto id_vertex = 0; id_vertex < size; id_vertex++)
	{
		for (auto i = 0; i < size; i++)
		{
			vertex_map[id_vertex][i] = i;
			vertex_cost[i] = adjacency_matrix[id_vertex][i];
		}

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size - 1; j++)
				if (vertex_cost[j] > vertex_cost[j + 1])
				{
					swap(vertex_map[id_vertex][j], vertex_map[id_vertex][j+1]);
					swap(vertex_cost[j], vertex_cost[j + 1]);
				}

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size - 1; j++)
				if (vertex_cost[j] <= 0)
				{
					swap(vertex_map[id_vertex][j], vertex_map[id_vertex][j + 1]);
					swap(vertex_cost[j], vertex_cost[j + 1]);
				}

		for (int i = 0; i < size; i++)
			if (vertex_cost[i] <= 0) vertex_map[id_vertex][i] = -1;
	}
	delete[] vertex_cost;
}

void Search::useVertex_(int x)
{
	if (isUsedVertex_(x)) releaseVertex_(x);
	tmp_path_.push_back(x);
}

bool Search::isUsedVertex_(int x) const
{
	for (auto i = 0; i < tmp_path_.size(); i++)
		if (tmp_path_[i] == x) return true;
	return false;
}

void Search::releaseVertex_(int x)
{
	for (auto i = tmp_path_.begin(); i != tmp_path_.end(); i++)
		if (*i == x)
		{
			tmp_path_.erase(i);
			break;
		}
}

// QUICKSORT
//void Search::_sort(int lewa, int prawa)
//{
//	int i = lewa;
//	int j = prawa;
//	Trasa x = trasa[(lewa + prawa) / 2];
//	do
//	{
//		while (trasa[i].pobierzKoszt() < x.pobierzKoszt()) i++;
//		while (trasa[j].pobierzKoszt() > x.pobierzKoszt()) j--;
//		if (i <= j)
//		{
//			swap(trasa[i], trasa[j]);
//			i++;
//			j--;
//		}
//	} while (i <= j);
//	if (lewa < j) _sortuj(lewa, j);
//	if (prawa > i) _sortuj(i, prawa);
//}