#include "Vertex.h"

using namespace std;

Vertex::Vertex(sf::Vector2f position, sf::Font & font, string name)
{
	setPos(position);
	setColor(sf::Color(255, 255, 255));

	shape.setRadius(20);
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color(0, 0, 0));
	shape.setOrigin(shape.getRadius(), shape.getRadius());

	text.setFont(font);
	text.setCharacterSize(14);
	text.setFillColor(sf::Color(0, 0, 0));
	setName(name);
}

Vertex::Vertex(float x, float y, sf::Font & font, string name) : Vertex(sf::Vector2f(x, y), font, name) {}

Vertex::~Vertex()
{

}

void Vertex::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(shape, states);
	target.draw(text, states);
}

string Vertex::getName() const
{
	return text.getString();
}

sf::Vector2f Vertex::getPos() const
{
	return shape.getPosition();
}

sf::CircleShape Vertex::getShape() const
{
	return shape;
}

void Vertex::setName(string name)
{
	text.setString(name);
}

void Vertex::setPos(sf::Vector2f pos)
{
	shape.setPosition(pos);
	text.setPosition(pos);
}

void Vertex::setColor(sf::Color color)
{
	shape.setFillColor(color);
}