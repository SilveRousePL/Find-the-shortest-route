#pragma once
#include <vector>
#include "Vertex.h"
#include "Path.h"
#include "File.h"

class Graph : public sf::Drawable, sf::Transformable
{
	File * file;
	std::vector <Vertex> vertex;
	std::vector <std::vector <uint8_t>> neighbor_matrix;
	size_t size;

public:
	Graph();
	~Graph();

	void draw(sf::RenderTarget &, sf::RenderStates) const final;

	void addVertex(Vertex vertex);
	void addConnect(Vertex * begin, Vertex * end);
	void remVertex(uint8_t id);
	void remConnect(uint8_t id_begin, uint8_t id_end);
	void eraseGraph();
	Path findShortestPath();

	size_t getSize() const;
	std::vector <std::vector <uint8_t>> getMatrix() const;

	void loadFromFile();
	void saveToFile();
};
