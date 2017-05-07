#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Button : public sf::Drawable, public sf::Transformable
{
	int width;
	int height;
	int char_size;

	sf::RectangleShape rectangle;
	sf::Text text;
	sf::Font font;
	sf::Color color;

public:
	Button();
	~Button();

	void draw(sf::RenderTarget&, sf::RenderStates&) const;
	void init(int width, int height, std::string name, int char_size);
	void setColor(sf::Color);
};

