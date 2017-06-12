#include "Button.h"

using namespace std;

Button::Button(string name, sf::Vector2f size, int font_size)
{
	if (size.x < 1 || size.y < 1) throw CriticalException("Button size is wrong");
	if (font_size < 1) throw CriticalException("Font size is wrong");
	if (!arial.loadFromFile("arial.ttf")) throw CriticalException("Error loading font");

	rec.setSize(size);
	rec.setFillColor(sf::Color(248, 248, 248));
	rec.setOutlineThickness(1);
	rec.setOutlineColor(sf::Color(128, 128, 128));

	text.setFont(arial);
	text.setCharacterSize(font_size);
	text.setString(name);
	text.setFillColor(sf::Color(0, 0, 0));
	

	is_hover = false;
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

void Button::hover(bool state)
{
	if (state && !is_hover)
	{
		rec.setFillColor(sf::Color(230, 230, 230));
		is_hover = true;
	}
	else if(!state && is_hover) rec.setFillColor(sf::Color(248, 248, 248));
}