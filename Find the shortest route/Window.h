#pragma once
#include <vector>
#include "Graph.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

enum objects;

class Window
{
	sf::RenderWindow window;
	sf::Event event;
	sf::Clock clock;

	Menu menu;
	Graph * graph;
	
	objects indicated_object;
	objects recently_indicated_object;

public:
	Window(int=800, int=600);
	~Window();

	void run();

private:
	void mainLoop(); //G³ówna pêtla programu
	void drawList(); //Lista elementów do rysowania
	void eventCheck(); //Obs³uga zdarzeñ
	void mouseOver(); //
};

enum objects
{
	NOTHING,
	MENU_BUTTON,
	ADD_VERTEX_BUTTON,
	ADD_CONNECT_BUTTON,
	REMOVE_VERTEX_BUTTON,
	REMOVE_CONNECT_BUTTON,
	FIND_BUTTON,
	BACKGROUND_MENU,
};