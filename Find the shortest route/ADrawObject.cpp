#include "ADrawObject.h"
#include "Exceptions.h"

ADrawObject::ADrawObject()
{

}

ADrawObject::~ADrawObject()
{
	for (auto i = 0; i < shape.size(); i++)
		delete shape[i];
}

void ADrawObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	for (auto i = shape.begin(); i != shape.end(); i++)
		target.draw(**i, states);
	for (auto i = text.begin(); i != text.end(); i++)
		target.draw(*i, states);
}