#include "Window.h"

using namespace std;

Window::Window(int width, int height) : menu(sf::Vector2f(width, height))
{
	if (width <= 0 || height <= 0) throw string("Incorrect window size");
	window.create(sf::VideoMode(width, height), "Find the shortest route - 235565");
	window.setFramerateLimit(60);
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
		eventCheck();
		animateList();
		drawList();

		window.display();
	}
}

void Window::drawList()
{
	window.draw(menu);
}

void Window::eventCheck()
{
	while(window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::M && !menu.slide)
		{
			menu.toggle();
		}
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
		{
		}
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Middle)
		{
			window.close();
		}
	}
}

void Window::animateList()
{
	if (menu.slide) menu.animate();
}