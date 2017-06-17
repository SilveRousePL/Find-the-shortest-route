#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Vertex : public sf::Drawable, public sf::Transformable
{
	int id;
	sf::CircleShape shape;
	sf::Text text;

public:
	Vertex(int id, sf::Vector2f position, sf::Font & font, std::string name);
	Vertex(int id, float x, float y, sf::Font & font, std::string name);
	~Vertex();

	void draw(sf::RenderTarget &, sf::RenderStates) const final;

	int getID();
	std::string getName() const;
	sf::Vector2f getPos() const;
	sf::CircleShape getShape() const;

	void setID(int id);
	void setName(std::string name);
	void setPos(sf::Vector2f pos);
	void setColor(sf::Color color);
};

