#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Vertex.h"

class Connect : public sf::Drawable, public sf::Transformable
{
	int id_begin;
	int id_end;
	sf::RectangleShape line;
	sf::Text cost;

	float length;
	float angle;

public:
	Connect(int id_begin, int id_end, sf::Font & font, unsigned int cost);
	~Connect();

	void draw(sf::RenderTarget &, sf::RenderStates) const final;
	void update(Vertex& vertex_begin, Vertex& vertex_end);
	double calcLength(Vertex & vertex_begin, Vertex & vertex_end) const;
	double calcAngle(Vertex & vertex_begin, Vertex & vertex_end) const;
	void changeID(int id_begin);

	sf::Vector2i getVertexID() const;
	sf::RectangleShape getShape() const;
	void setCost(unsigned int c);
	void setColor(sf::Color color);
};
