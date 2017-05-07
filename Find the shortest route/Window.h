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

	void mainLoop(); //G³ówna pêtla programu
	void eventCheck(); //Obs³uga zdarzeñ
	void buttonRender();
};
