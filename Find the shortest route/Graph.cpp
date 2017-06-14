#include "Graph.h"

Graph::Graph()
{
	vertex.push_back(Vertex(60, 20));
	vertex.push_back(Vertex(20, 40));
	vertex.push_back(Vertex(60, 50));
}

Graph::~Graph()
{

}

void Graph::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	for (auto i = vertex.begin(); i != vertex.end(); i++)
		target.draw(*i, states);
}

void Graph::addVertex(Vertex vertex)
{
	this->vertex.push_back(vertex);
	this->vertex.back(Vertex()).
}

void Graph::addConnect(Vertex* begin, Vertex* end)
{

}

void Graph::remVertex(uint8_t id)
{

}

void Graph::remConnect(uint8_t id_begin, uint8_t id_end)
{

}

void Graph::eraseGraph()
{

}

Path Graph::findShortestPath()
{

}

size_t Graph::getSize() const
{
	return size;
}

std::vector<std::vector<uint8_t>> Graph::getMatrix() const
{
	return neighbor_matrix;
}
