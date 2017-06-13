#pragma once
#include <vector>
#include "Vertex.h"

class Path
{
	std::vector <Vertex*> vertex;
	uint8_t cost;

public:
	Path(std::vector <uint8_t> & id_vertex, uint8_t cost);
	~Path();

	uint8_t getCost() const;
};

