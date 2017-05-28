#pragma once
#include <SFML/Graphics.hpp>
#include "Exceptions.h"

class Button : public sf::Drawable, public sf::Transformable
{
	friend class Menu;

	sf::RectangleShape rec;
	sf::Font arial;
	sf::Text text;

public:
	Button(std::string, sf::Vector2f, int=36);
	~Button();

	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	sf::Vector2f getSize();
};
