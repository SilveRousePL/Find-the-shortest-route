#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Graph.h"
#include "File.h"
#include "enumTypes.h"

class Window
{
	sf::RenderWindow window;
	sf::Event event;
	sf::Clock clock;
	sf::Font font;
	Graph * graph;
	File * file;
	sf::Text dialog;
	Mode mode; //enum, przechowuje obecny tryb dzia�ania

	int id_buffer;
	std::string text_buffer;

public:
	Window(int=800, int=600);
	~Window();

	void run();

private:
	void render(); //G��wna p�tla programu
	void eventCheck(); //Obs�uga zdarze�
	void mouseEvent();
	void keyboardEvent();

	void setDialog(std::string text); //UStawia komunikat w dolnej cz�ci okna
	void closeApp(); //Zamyka aplikacj�
};