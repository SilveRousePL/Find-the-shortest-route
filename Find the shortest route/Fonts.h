#pragma once
#include <SFML/Graphics/Font.hpp>
#include "Exceptions.h"

sf::Font * arial;

inline void loadFonts()
{
	arial = new sf::Font;
	if (!arial->loadFromFile("arial.ttf")) throw CriticalException("Error loading font");
}

inline sf::Font getArial()
{
	return *arial;
}