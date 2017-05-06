#pragma once
#include <vector>
#include "File.h"
#include "Vertex.h"
#include "Connect.h"
#include "Path.h"

using namespace std;

class Graph
{
	File file;
	vector<Vertex> vertex;
	vector<Connect> connect;
	Path shortest_path;

public:
	Graph();
	~Graph();
};

