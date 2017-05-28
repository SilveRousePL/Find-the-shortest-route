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
	void mainLoop(); //G��wna p�tla programu
	void drawList(); //Lista element�w do rysowania
	void eventCheck(); //Obs�uga zdarze�
	void animateList(); //Lista element�w do animacji
};
