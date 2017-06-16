#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Vertex : public sf::Drawable, public sf::Transformable
{
	sf::CircleShape shape;
	sf::Text text;

public:
	Vertex(sf::Vector2f position, sf::Font & font, std::string name);
	Vertex(float x, float y, sf::Font & font, std::string name);
	~Vertex();

	void draw(sf::RenderTarget &, sf::RenderStates) const final;

	std::string getName() const;
	sf::Vector2f getPos() const;
	sf::CircleShape getShape() const;

	void setName(std::string name);
	void setPos(sf::Vector2f pos);
	void setColor(sf::Color color);
};

