#pragma once
#include <SFML/Graphics.hpp>
#include "Exceptions.h"

class Button : public sf::Drawable, public sf::Transformable
{
	friend class Menu;
	friend class Window;

	sf::RectangleShape rec;
	sf::Font arial;
	sf::Text text;
	bool is_hover;

public:
	Button(std::string, sf::Vector2f, int=12);
	~Button();

	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	void hover(bool);
};
