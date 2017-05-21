#include "DButton.h"

DButton::DButton()
{
	rectangle.setOutlineThickness(2);
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	init(32, 32, "New button", 8);
}

DButton::~DButton()
{

}

void DButton::draw(sf::RenderTarget& target, sf::RenderStates& states) const
{
	target.draw(rectangle);
	target.draw(text);
}

void DButton::init(int width, int height, std::string name, int char_size)
{
	if (width < 1 || height < 1 || char_size < 1) throw std::string("New button size is wrong");

	this->width = width;
	this->height = height;
	this->char_size = char_size;

	rectangle.setSize(sf::Vector2f(this->width, this->height));
	text.setCharacterSize(char_size);
	text.setString(name);
}

void DButton::setColor(sf::Color)
{
	this->color = color;
	rectangle.setOutlineColor(this->color);
}