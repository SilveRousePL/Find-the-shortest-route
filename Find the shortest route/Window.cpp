#include "Window.h"

using namespace std;

Window::Window(int width, int height) : menu(sf::Vector2f(width, height))
{
	if (width <= 0 || height <= 0) throw string("Incorrect window size");
	window.create(sf::VideoMode(width, height), "Find the shortest route - 235565");
	window.setFramerateLimit(60);
	
	indicated_object = NOTHING;
	recently_indicated_object = NOTHING;
}

Window::~Window()
{

}

void Window::run()
{
	this->mainLoop();
}

void Window::mainLoop()
{
	while (window.isOpen())
	{
		window.clear(sf::Color(64, 64, 64));
		recently_indicated_object = indicated_object;
		indicated_object = NOTHING;

		mouseOver();
		eventCheck();
		drawList();

		window.display();
	}
}

void Window::drawList()
{
	window.draw(menu);
}

void Window::mouseOver()
{
		if (menu.button[0].rec.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
		{
			indicated_object = MENU_BUTTON;
			return;
		}

		if (menu.button[1].rec.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
		{
			indicated_object = ADD_VERTEX_BUTTON;
			return;
		}

		if (menu.button[2].rec.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
		{
			indicated_object = ADD_CONNECT_BUTTON;
			return;
		}

		if (menu.background.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))) && menu.is_show)
		{
			indicated_object = BACKGROUND_MENU;
			return;
		}
}

void Window::eventCheck()
{
	while(window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::M)
		{
			menu.toggle();
		}
		
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Middle)
		{
			window.close();
		}

		switch (indicated_object)
		{
		case MENU_BUTTON:
			menu.button[MENU_BUTTON].hover(true);
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				menu.toggle();
			break;
		case ADD_VERTEX_BUTTON:
			cout << "ADD_VERTEX" << endl;
			break;
		case ADD_CONNECT_BUTTON:
			cout << "ADD_CONN" << endl;
			break;
		case BACKGROUND_MENU:
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				menu.toggle();
			cout << "BG_MENU" << endl;
			break;
		}

		if (recently_indicated_object != indicated_object && recently_indicated_object <= FIND_BUTTON)
		{
			menu.button[recently_indicated_object].hover(false);
		}
	}
}