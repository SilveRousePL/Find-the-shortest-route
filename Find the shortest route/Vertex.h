#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Vertex : public sf::Drawable, sf::Transformable
{
	sf::Vector2f position;
	sf::CircleShape shape;
	sf::Text text;

public:
	Vertex(sf::Vector2f position, sf::Font font, std::string name="");
	Vertex(float x, float y, sf::Font font, std::string name="");
	~Vertex();

	void draw(sf::RenderTarget &, sf::RenderStates) const final;

	sf::Vector2f getPosition() const;

	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);
	void setName(std::string name);
	void setColor(sf::Color color);
	
};

