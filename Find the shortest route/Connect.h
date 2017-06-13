#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Vertex.h"

class Connect : public sf::Drawable, public sf::Transformable
{
	//UI
	Vertex * vertex_begin;
	Vertex * vertex_end;
	sf::RectangleShape line;
	sf::Text cost;

	float length;
	float angle;

public:
	Connect(Vertex * begin, Vertex * end, sf::Font font, std::string cost="NaN");
	~Connect();

	void draw(sf::RenderTarget &, sf::RenderStates) const final;
	void update();

	void setCost(std::string cost);
	void setColor(sf::Color color, float outline_thickness = 10);

private:
	double calcLength() const;
	double calcAngle() const;
};
