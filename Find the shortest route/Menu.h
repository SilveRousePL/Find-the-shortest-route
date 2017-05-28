#pragma once
#include "Button.h"

class Menu : public sf::Drawable, public sf::Transformable
{
	friend class Window;

	sf::Vector2f size;
	sf::RectangleShape bar;
	sf::RectangleShape background;
	Button menu_toggle;
	std::vector<Button> button;

	sf::Clock timer;
	bool is_show;
	bool slide;
	void animate();

	float slide_time;

public:
	Menu(sf::Vector2f);
	~Menu();

	void draw(sf::RenderTarget &, sf::RenderStates) const override;
	void toggle();
};

