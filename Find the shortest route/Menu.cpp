#include "Menu.h"

Menu::Menu(sf::Vector2f size) : menu_toggle("Menu", sf::Vector2f(size.x / 3 + 100, 100))
{
	this->size = sf::Vector2f(size.x / 3, size.y);

	bar.setSize(this->size);
	bar.setPosition(sf::Vector2f(0 - bar.getSize().x, 0));
	bar.setFillColor(sf::Color(255,255,255));
	bar.setOutlineThickness(3);
	bar.setOutlineColor(sf::Color(0, 0, 0, 128));

	menu_toggle.setPosition(0 - bar.getSize().x, size.y - 100);
	menu_toggle.rec.setFillColor(sf::Color(255, 255, 255));
	menu_toggle.rec.setOutlineThickness(3);
	menu_toggle.rec.setOutlineColor(sf::Color(0, 0, 0, 128));

	background.setSize(sf::Vector2f(size.x, size.y));
	background.setPosition(sf::Vector2f(0, 0));
	//background.setFillColor(sf::Color(255,255,255,0));

	is_show = false;
	slide = false;

	slide_time = 1.0f;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	if (is_show || slide)
	{
		target.draw(background, states);
		target.draw(bar, states);
		for (auto i = button.begin(); i != button.end(); i++)
			target.draw(*i, states);
	}
	target.draw(menu_toggle, states);
}

void Menu::animate()
{
	float f_time = timer.getElapsedTime().asSeconds();
	if (f_time < slide_time)
	{
		if (is_show) //Chowanie
		{
			bar.setPosition(0 - bar.getSize().x * f_time / slide_time, 0);
			menu_toggle.setPosition(0 - bar.getSize().x * f_time / slide_time, menu_toggle.getPosition().y);
			background.setFillColor(sf::Color(255, 255, 255, 128 - f_time / slide_time * 128));
		}
		else //Pokazywanie
		{
			bar.setPosition(0 - bar.getSize().x + bar.getSize().x * f_time / slide_time, 0);
			menu_toggle.setPosition(0 - bar.getSize().x + bar.getSize().x * f_time / slide_time, menu_toggle.getPosition().y);
			background.setFillColor(sf::Color(255, 255, 255, f_time / slide_time * 128));
		}
	}
	else
	{
		slide = false;
		if (is_show) is_show = false;
		else is_show = true;
	}
}

void Menu::toggle()
{
	timer.restart();
	slide = true;
}
/*
void Menu::show()
{
	if (timer.getElapsedTime().asSeconds() < slide_time)
	{
		bar.setPosition(0 - bar.getSize().x + bar.getSize().x * timer.getElapsedTime().asSeconds() / slide_time, 0);
		menu_toggle.setPosition(0 - bar.getSize().x + bar.getSize().x * timer.getElapsedTime().asSeconds() / slide_time, menu_toggle.getPosition().y);
		background.setFillColor(sf::Color(255, 255, 255, timer.getElapsedTime().asSeconds() / slide_time * 128));
	}
	else
	{
		slide = false;
		is_show = true;
	}
}

void Menu::hide()
{
	if (timer.getElapsedTime().asSeconds() < slide_time)
	{
		bar.setPosition(0 - bar.getSize().x * timer.getElapsedTime().asSeconds() / slide_time, 0);
		menu_toggle.setPosition(0 - bar.getSize().x * timer.getElapsedTime().asSeconds() / slide_time, menu_toggle.getPosition().y);
		background.setFillColor(sf::Color(255, 255, 255, 128 - timer.getElapsedTime().asSeconds() / slide_time * 128));
	}
	else
	{
		slide = false;
		is_show = false;
	}
}

void Menu::animate()
{
	if (!is_show) this->show();
	else this->hide();
} */