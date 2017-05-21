#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Vertex : public sf::Drawable, public sf::Transformable
{
	string name;
	int x;
	int y;

	sf::CircleShape circle;
	sf::Text text;
	sf::Font font;
	sf::Color color;

public:
	Vertex();
	~Vertex();

	void draw(sf::RenderTarget & target, sf::RenderStates & states) const;

	void setColor(sf::Color);
};

