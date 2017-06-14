#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Vertex : public sf::Drawable, sf::Transformable
{
	uint8_t id;
	sf::Vector2f position;
	sf::CircleShape shape;
	sf::Text text;
	static sf::Font * font;

public:
	Vertex(uint8_t id, sf::Vector2f position, std::string name="");
	Vertex(uint8_t id, float x, float y, std::string name="");
	~Vertex();

	void draw(sf::RenderTarget &, sf::RenderStates) const final;

	uint8_t getID() const;
	std::string getName() const;
	sf::Vector2f getPos() const;

	void setPos(sf::Vector2f position);
	void setPos(float x, float y);
	void setFont(sf::Font & font);
	void setName(std::string name);
	void setColor(sf::Color color);
};

