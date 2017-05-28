#include "Menu.h"

using namespace std;

Menu::Menu(sf::Vector2f size)
{
	window_size = size;
	is_show = false;

	createMenu();
	createButton();
}

Menu::~Menu()
{

}

void Menu::createMenu()
{
	bar.setSize(sf::Vector2f(window_size.x, 40));
	bar.setPosition(sf::Vector2f(0, 0));
	bar.setFillColor(sf::Color(255, 255, 255));
	bar.setOutlineThickness(1);
	bar.setOutlineColor(sf::Color(128, 128, 128));

	background.setSize(sf::Vector2f(window_size.x, window_size.y - 40));
	background.setPosition(sf::Vector2f(0, 40));
	background.setFillColor(sf::Color(0, 0, 0, 128));
}

void Menu::createButton()
{
	const string name[] = { "Menu", "Add Vertex", "Add Connect", "Remove Vertex", "Remove Connect", "Find the shortest path" };
	for (int i = 0; i < amount; i++)
	{
		Button * tmp = new Button(name[i], sf::Vector2f(120, 40));
		tmp->setPosition(sf::Vector2f(130 * i, 0));
		button.push_back(*tmp);
	}
}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	if (is_show)
	{
		target.draw(background, states);
		target.draw(bar, states);
		for (auto i = button.begin() + 1; i != button.end(); i++)
			target.draw(*i, states);
	}
	target.draw(button[0], states);
}

void Menu::toggle()
{
	is_show ? is_show = false : is_show = true;
}