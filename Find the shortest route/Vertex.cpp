#include "Vertex.h"

using namespace std;

Vertex::Vertex(int id, sf::Vector2f position, sf::Font & font, string name="")
{
	shape.setRadius(20);
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color(0, 0, 0));
	shape.setOrigin(shape.getRadius(), shape.getRadius());

	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color(0, 0, 0));

	setID(id);
	setPos(position);
	setColor(sf::Color(255, 255, 255));

	setName(name);
}

Vertex::Vertex(int id, float x, float y, sf::Font & font, string name) : Vertex(id, sf::Vector2f(x, y), font, name) {}

Vertex::~Vertex()
{

}

void Vertex::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(shape, states);
	target.draw(text, states);
}

int Vertex::getID()
{
	return id;
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

void Vertex::setID(int id)
{
	if (id >= 0) this->id = id;
}

void Vertex::setName(string name)
{
	if (name.length() == 0) name = to_string(id);
	text.setString(name);
}

void Vertex::setPos(sf::Vector2f pos)
{
	shape.setPosition(pos);
	text.setPosition(pos.x - 10, pos.y - 10);
}

void Vertex::setColor(sf::Color color)
{
	shape.setFillColor(color);
}