#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class ADrawObject : public sf::Drawable, public sf::Transformable
{
protected:
	std::vector <sf::Sprite> sprite;
	std::vector <sf::Shape*> shape;
	std::vector <sf::Text> text;
	
public:
	ADrawObject();
	~ADrawObject();

	void draw(sf::RenderTarget &, sf::RenderStates) const override;

protected:
	virtual void gCreate() = 0;
};
