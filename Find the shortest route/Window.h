#pragma once
#include "Graph.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Window
{
	sf::RenderWindow window;
	sf::Event event;

	Graph graph;
	Button * button;

public:
	Window();
	Window(int, int);
	~Window();

	void mainLoop(); //G��wna p�tla programu
	void eventCheck(); //Obs�uga zdarze�
	void buttonRender();
};
