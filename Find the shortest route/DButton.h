#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "ADrawObject.h"

class DButton :public ADrawObject
{
	int width;
	int height;
	int char_size;

	sf::RectangleShape rectangle;
	sf::Text text;
	sf::Font font;
	sf::Color color;

public:
	DButton();
	~DButton();

	void init(int width, int height, std::string name, int char_size);
};

