#include "Window.h"

using namespace std;

Window::Window() : Window(800, 600) {}

Window::Window(int width, int height)
{
	if (width <= 0 || height <= 0) throw string("B³êdny rozmiar okna");
	window.create(sf::VideoMode(width, height), "Find the shortest route - 235565");
}

Window::~Window()
{

}

void Window::mainLoop()
{
	while (window.isOpen())
	{
		window.clear();
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
	}
}

void Window::buttonRender()
{
	
}