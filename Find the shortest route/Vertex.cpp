#include "Vertex.h"

using namespace std;

Vertex::Vertex(uint8_t id, sf::Vector2f position, string name) : id(id)
{
	setPosition(position);
	setColor(sf::Color(255, 255, 255));

	shape.setRadius(30);
	shape.setOutlineThickness(1);
	shape.setOutlineColor(sf::Color(0, 0, 0));

	text.setFillColor(sf::Color(0, 0, 0));
	setName(name);
}

Vertex::Vertex(uint8_t id, float x, float y, string name) : Vertex(id, sf::Vector2f(x, y), name) {}

Vertex::~Vertex()
{

}

void Vertex::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(shape, states);
	target.draw(text, states);
}

uint8_t Vertex::getID() const
{
	return id;
}

string Vertex::getName() const
{
	return text.getString();
}

sf::Vector2f Vertex::getPos() const
{
	return position;
}

void Vertex::setPos(sf::Vector2f position)
{
	this->position = position;
}

void Vertex::setPos(float x, float y)
{
	setPosition(sf::Vector2f(x, y));
}

void Vertex::setFont(sf::Font & _font)
{
	this->font = &_font;
	text.setFont(*font);
}

void Vertex::setName(std::string name)
{
	text.setFont(*font);
	text.setString(name);
}

void Vertex::setColor(sf::Color color)
{
	shape.setFillColor(color);
}