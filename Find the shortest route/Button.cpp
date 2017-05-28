#include "Button.h"

using namespace std;

Button::Button(string name, sf::Vector2f size, int font_size)
{
	if (size.x < 1 || size.y < 1) throw CriticalException("Button size is wrong");
	if (font_size < 1) throw CriticalException("Font size is wrong");
	if (!arial.loadFromFile("arial.ttf")) throw CriticalException("Error loading font");

	rec.setSize(size);
	rec.setFillColor(sf::Color(255, 255, 255));
	text.setFont(arial);
	text.setCharacterSize(font_size);
	text.setString(name);
	text.setFillColor(sf::Color(0, 0, 0));
	text.move(sf::Vector2f((size.x - text.getGlobalBounds().width) / 2, (size.y - text.getGlobalBounds().height) / 2 ));
}

Button::~Button()
{

}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(rec, states);
	target.draw(text, states);
}