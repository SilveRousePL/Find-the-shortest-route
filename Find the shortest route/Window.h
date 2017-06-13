#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "Graph.h"

class Window
{
	sf::RenderWindow window;
	sf::Event event;
	ResourceManager resource;

	Graph * graph;

public:
	Window(int=800, int=600);
	~Window();

	void run();

private:
	void render(); //G³ówna pêtla programu
	void eventCheck(); //Obs³uga zdarzeñ
	void mouseOver(); //
};
