#pragma once
#include "Graph.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Window
{
	sf::RenderWindow window;
	sf::Event event;
	sf::Clock clock;

	Graph * graph;
	Menu menu;

public:
	Window(int=800, int=600);
	~Window();

	void run();

private:
	void mainLoop(); //G³ówna pêtla programu
	void drawList(); //Lista elementów do rysowania
	void eventCheck(); //Obs³uga zdarzeñ
	void animateList(); //Lista elementów do animacji
};
