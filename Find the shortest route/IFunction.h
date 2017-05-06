#pragma once
#include "Graph.h"

class IFunction
{
public:
	Graph OpenFile();
	void SaveFile(Graph);
	void Erase(Graph);
	void AddVertex(Graph, int, int);
	void AddConnect(Graph, Vertex, Vertex, int);
	void DeleteVertex(Graph, Vertex);
	void DeleteConnect(Graph, Connect);
	void FindPath(Graph);
};

