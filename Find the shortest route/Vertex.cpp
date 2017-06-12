#include "Vertex.h"

using namespace std;

Vertex::Vertex(sf::Vector2f position, sf::Font font, string name)
{
	setPosition(position);
	setColor(sf::Color(255, 255, 255));

	shape.setRadius(30);
	shape.setOutlineThickness(1);
	shape.setOutlineColor(sf::Color(0, 0, 0));

	text.setFont(font);
	text.setFillColor(sf::Color(0, 0, 0));
	setName(name);
}

Vertex::Vertex(float x, float y, sf::Font font, string name) : Vertex(sf::Vector2f(x, y), font, name) {}

Vertex::~Vertex()
{

}

void Vertex::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(shape, states);
	target.draw(text, states);
}

sf::Vector2f Vertex::getPosition() const
{
	return position;
}

void Vertex::setPosition(sf::Vector2f position)
{
	this->position = position;
}

void Vertex::setPosition(float x, float y)
{
	setPosition(sf::Vector2f(x, y));
}

void Vertex::setName(std::string name)
{
	text.setString(name);
}

void Vertex::setColor(sf::Color color)
{
	shape.setFillColor(color);
}