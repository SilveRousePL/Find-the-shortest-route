#pragma once
#include "Button.h"

class Menu : public sf::Drawable, public sf::Transformable
{
	friend class Window;

	static const int amount = 6;

	sf::RectangleShape bar;
	sf::RectangleShape background;
	sf::Vector2f window_size;
	std::vector<Button> button;

	bool is_show;

public:
	Menu(sf::Vector2f);
	~Menu();

	void createMenu();
	void createButton();
	
	void draw(sf::RenderTarget &, sf::RenderStates) const override;
	void toggle();
};

