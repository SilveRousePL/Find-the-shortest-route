#pragma once
#include <vector>
#include "Vertex.h"
#include "Connect.h"
#include "Path.h"
#include "Search.h"

class Graph : public sf::Drawable, public sf::Transformable
{
	typedef std::vector<std::vector<int>> Matrix;
	Matrix adjacency;
	std::vector <Vertex> vertex;
	std::vector <Connect> connect;
	sf::Font font;

public:
	Graph();
	~Graph();

	void draw(sf::RenderTarget &, sf::RenderStates) const final;

	void newGraph();
	void addVertex(sf::Vector2f pos);
	void addConnect(int id_begin, int id_end, unsigned int cost);
	void remVertex(int id_vertex);
	void remConnect(int id_connect);
	Path findShortestPath(int id_begin, int id_end);

	size_t getSize() const;
	std::vector <Vertex> getVertex() const;
	Matrix getMatrix() const;
	int getIDConnectByVertexsID(int id_begin, int id_end) const;

	void setVertexPosition(int id, sf::Vector2f position);
	void setFont(sf::Font font);
	void setColorV(int id, sf::Color color);
	void setColorC(int id, sf::Color color);
	void coloringPath(Path path, sf::Color color);
	void deleteColoring(sf::Color color);

	int detectVertex(sf::Vector2f position);
	int detectConnect(sf::Vector2f position);
	void refreshConnects();
};
