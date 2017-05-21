#pragma once
#include <SFML/Graphics.hpp>

class ADrawObject :public sf::Drawable, public sf::Transformable
{
	ADrawObject();
	~ADrawObject();

	virtual void draw(sf::RenderTarget &, sf::RenderStates &) const;
	virtual void setColor(sf::Color);
};

