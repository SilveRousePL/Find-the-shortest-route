#pragma once
#include "ADrawObject.h"

using namespace std;

class Vertex : public ADrawObject
{
	string name;
	int x;
	int y;

public:
	Vertex();
	~Vertex();

	void gCreate() override;
};

