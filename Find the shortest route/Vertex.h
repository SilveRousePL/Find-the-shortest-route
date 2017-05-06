#pragma once
#include <string>
#include <vector>

using namespace std;

class Vertex
{
	string name;
	int x;
	int y;
	vector<Vertex> vertex_n;
	vector<int> vertex_c;
	int color[3];

public:
	Vertex();
	~Vertex();

	void SetColor(int[3]);
};

