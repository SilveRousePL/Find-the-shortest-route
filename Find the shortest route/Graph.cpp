#include "Graph.h"

Graph::Graph()
{
	vertex.push_back(Vertex(20, 20));
	vertex.push_back(Vertex(60, 20));
	vertex.push_back(Vertex(20, 40));
	vertex.push_back(Vertex(60, 50));
	connect.push_back(Connect(&vertex[0], &vertex[1]));
}


Graph::~Graph()
{
}

void Graph::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	for (auto i = vertex.begin() + 1; i != vertex.end(); i++)
		target.draw(*i, states);
	for (auto i = connect.begin() + 1; i != connect.end(); i++)
		target.draw(*i, states);
}

size_t Graph::getSize() const
{
	return vertex.size();
}