#pragma once
#include <vector>
#include "Vertex.h"
#include "Connect.h"
#include "Path.h"

class Graph
{
	std::vector <Vertex> vertex;
	std::vector <Connect> connect;

public:
	Graph();
	~Graph();
};

