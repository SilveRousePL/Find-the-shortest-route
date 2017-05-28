#pragma once
#include "ADrawObject.h"

class Vertex : public ADrawObject
{
	std::string name;
	int x;
	int y;

public:
	Vertex();
	~Vertex();

	void gCreate() override;
};

