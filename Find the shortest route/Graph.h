#pragma once
#include <vector>
#include "Vertex.h"
#include "Path.h"

class Graph : public sf::Drawable, sf::Transformable
{
	std::vector <Vertex> vertex;

public:
	Graph();
	~Graph();

	void draw(sf::RenderTarget &, sf::RenderStates) const final;

	void addVertex(Vertex);
	void addConnect();

	size_t getSize() const;
	Path getShortestPath();
};