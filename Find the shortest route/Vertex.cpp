#include "Vertex.h"



Vertex::Vertex()
{
}


Vertex::~Vertex()
{
}

void Vertex::draw(sf::RenderTarget& target, sf::RenderStates& states) const
{
	target.draw(circle);
	target.draw(text);
}