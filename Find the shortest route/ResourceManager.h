#pragma once
#include "Exceptions.h"
#include <SFML/Graphics/Font.hpp>

class ResourceManager
{
	sf::Font font_holder_;

public:
	ResourceManager();
	~ResourceManager();

	void loadFont(std::string font_path);
	sf::Font & getFont();
};